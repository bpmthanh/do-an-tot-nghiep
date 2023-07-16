#include <SoftwareSerial.h>
SoftwareSerial SIM800A (26, 27);
SoftwareSerial esp(32, 33);
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <String.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "web.h"
#include <string.h>


const char * ssid = "ThanhBui";
const char * password = "autoship";

const char* serverName = "https://hcmusiotproject.000webhostapp.com/data_client.php";
String apiKeyValue = "tPmAT5Ab3j7F9";

const char* serverNameHistoryClient = "https://hcmusiotproject.000webhostapp.com/history_client.php";
String apiKeyValueHistoryClient = "tPmAT5Ab3j7F8";

String GOOGLE_SCRIPT_ID = "AKfycbwf6vVyl5Rjouch_7mIAUm3hFX2cgXf49TCFa9nEEDiXuPPRv53kQT0e3MR0Iu_fW1a";

int dulieu;
WebServer server (80);
WiFiClient client;
void SendWebPage();
void  ConnectWifi ();
void  Send_Data();
long last = millis();
long last1 = millis();
long last2 = millis();
String param;

float h;
float t;
int danggoi = 0;
String a;
String b;
String DataSendWeb = "";
int dem = 0;

void  SendMessage(int c) {
  if (c == 1)
  {
    SIM800A.println("AT");
    SIM800A.println("AT+CMGS=\"+84924694598\"\r");
    delay(300);
    SIM800A.println("Nhiet do qua cao");
    delay(300);
    SIM800A.println((char)26);
    Serial.println("Hoan thanh");
  }
  else if (c == 0)
  {
    SIM800A.println("AT");
    SIM800A.println("AT+CMGS=\"+84924694598\"\r");
    delay(300);
    SIM800A.println(WiFi.localIP());
    delay(300);
    SIM800A.println((char)26);
    Serial.println("Hoan thanh");
  }
  else if (c == 2)
  {
    SIM800A.println("AT");
    SIM800A.println("AT+CMGS=\"+84924694598\"\r");
    delay(300);
    SIM800A.println("Co truong hop dot nhap");
    delay(300);
    SIM800A.println((char)26);
    Serial.println("Hoan thanh");
  }
}

void GOI()
{
  danggoi = 1;
  SIM800A.println("AT");
  SIM800A.println("ATD0924694598;");
  Serial.println ("Goi.......");
  delay(20000);
  last2 = millis();
}

void NhanTinNhan()
{
  Serial.println("\nDa nhan module tin nhan");
  String response = SIM800A.readString();
  Serial.println(response);
  a = response.substring(50, response.length() - 1);
  Serial.println(a);
  b = response.substring(10, 21);
  Serial.println(b);
  if (b.indexOf("84924694598") >= 0)
  {
    if (response.indexOf("OPEN") >= 0)
    {
      gui(9);
    }
    else if (response.indexOf("WIFI") >= 0) {
      SendMessage(0);
    }
  }
}

void  Send_Data()
{
  server.send(200, "text/html", String(DataSendWeb));
}

void SendWebPage()
{
  server.send(200, "text/html", webpage );
}

void gui(int dulieu)
{
  String data = String(dulieu);
  esp.println(data);
  Serial.print("\nDa gui du lieu: ");
  Serial.println(data);
}





//void Connect_Wifi()
//{
//  WiFi.mode(WIFI_STA);
//  Serial.print("Connecting to WiFi");
//  WiFi.begin(ssid, password);
//  Serial.println(ssid);
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("CONNECTED !!!");
//
//  IPAddress staticIP(192, 168, 137, 176); // Địa chỉ IP cố định
//  IPAddress gateway(192, 168, 137, 1); // Địa chỉ gateway của mạng
//  IPAddress subnet(255, 255, 255, 0); // Mặt nạ mạng
//
//  WiFi.config(staticIP, gateway, subnet);
//
//  // Kiểm tra nếu địa chỉ IP đã được gán thành công
//  if (WiFi.localIP() == staticIP)
//  {
//    Serial.println("Connect WiFi");
//    Serial.print("Address IP ESP: ");
//    Serial.println(WiFi.localIP());
//  }
//  else
//  {
//    Serial.println("Failed to set static IP!");
//  }
//}




void  Connect_Wifi()
{
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED !!!");
  Serial.println("Connect WiFi");
  Serial.print("Address IP ESP: ");
  Serial.println(WiFi.localIP());
}






int nowN = -1;
void getDataFromSQL()
{
  HTTPClient http;
  http.begin(String(serverName) + "?api_key=" + String(apiKeyValue));
  int httpResponseCode = http.GET();
  if (httpResponseCode == HTTP_CODE_OK) {  // HTTP_CODE_OK tương đương với 200 OK
    String payload = http.getString();

    Serial.println("\n");
    Serial.println(payload);


    int n = 0;
    int pos = 0;
    while ((pos = payload.indexOf("}", pos)) != -1) {
      n++;
      pos++;
    }
    

    const size_t capacity = JSON_ARRAY_SIZE(n) + n * JSON_OBJECT_SIZE(4) + 220;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, payload);
    int ids[n];
    int i = 0;
    for (JsonObject obj : doc.as<JsonArray>()) {
      int id = obj["id"];
      ids[i] = id;
      i++;
    }

    if (n != nowN) {
      nowN = n;
      Serial.println("\nGet amount, data ID and send to arduino: ");
      Serial.print("So luong user: "); Serial.println(n);
      esp.println("So luong user: " + String(n));
      for (int i = 0; i < sizeof(ids) / sizeof(ids[0]); i++) {
        String strID = String(ids[i]); // chuyển từng số thành string
        esp.println(strID); // gửi dữ liệu dạng string
        Serial.print("Da gui ID user: ");
        Serial.println(ids[i]);
        delay(300);
      }
    }
  }
}





void sendDataToSQLAndAdd(String mathe, String ten)   //CONNECTING WITH MYSQL
{
  HTTPClient http;
  http.begin(serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String httpRequestData = "api_key=" + apiKeyValue + "&id=" + mathe + "&name=" + ten
                           + "&location=" + "Ha Noi";
  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);

  int httpResponseCode = http.POST(httpRequestData);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}




void sendDataHistoryToSQLAndAdd(String mathe, String ten)   //CONNECTING WITH MYSQL
{
  HTTPClient http;
  http.begin(serverNameHistoryClient);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String httpRequestData = "api_key=" + apiKeyValueHistoryClient + "&id=" + mathe + "&name=" + ten
                           + "&location=" + "Ha Noi";
  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);

  int httpResponseCode = http.POST(httpRequestData);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}



void senDataToSQLAndDel(String mathe) {
  HTTPClient http;
  http.begin(serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String httpRequestData = "api_key=" + apiKeyValue + "&id=" + mathe + "&action=delete";
  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);

  int httpResponseCode = http.POST(httpRequestData);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}



void setup()
{
  Serial.begin(19200);
  esp.begin(19200);
  SIM800A.begin(19200);

  server.on("/Update", [] {
    Send_Data();
  });
  server.on("/mocua", [] {
    gui(9);
  });
  server.on("/doimatkhau", [] {
    gui(10);
  });
  server.on("/themthe", [] {
    gui(11);
  });
  server.on("/xoathe", [] {
    gui(12);
  });
  server.on("/1lop", [] {
    gui(8);
  });
  server.on("/2lop", [] {
    gui(7);
  });


  Serial.println("\n");
  SIM800A.println("AT+CPMS=\"SM\",\"SM\",\"SM\""); // Chọn bộ nhớ lưu trữ
  delay(1000);
  SIM800A.println("AT+CNMI=1,2,0,0,0"); // Cấu hình module để thông báo khi có tin nhắn mới
  delay(1000);
  SIM800A.println("AT+CMGF=1");
  String response = SIM800A.readString();
  if (response.indexOf("=1\r\n\r\nM\",\"SM\",\"SM\"") == -1) {
    Serial.println(response);
  }


  Connect_Wifi();
  server.begin();
  Serial.println("Sever Start!!!!");
  server.on("/", [] {
    SendWebPage();
  });
}


boolean wifiConnected = false; // Biến flag để kiểm tra trạng thái kết nối WiFi
void loop()
{
    if (!wifiConnected) {
      Serial.println("\n");
      Connect_Wifi(); // Kết nối WiFi khi mất kết nối hoặc chưa kết nối
    }
    // Kiểm tra trạng thái kết nối WiFi
    if (WiFi.status() != WL_CONNECTED) {
      wifiConnected = false; // Kết nối mất, cần kết nối lại
    } else {
      wifiConnected = true; // Đã kết nối WiFi
    }



  if ((danggoi == 1 ) && (millis() - last2 > 30000))
  {
    danggoi = 0;
    SIM800A.println("ATH");
  }
  server.handleClient();
  if (esp.available())
  {
    String mathe = esp.readStringUntil('\n') ;

    if (mathe.indexOf("spam") >= 0)
    {
      GOI();
      SendMessage(2) ;
    }

    if (mathe.startsWith("Xoa the ")) {
      String maTheBiXoa = mathe.substring(8); // tách số từ vị trí 15 của chuỗi và chuyển thành số nguyên
      Serial.print("\nDa nhan ma the bi xoa: ");
      Serial.println(maTheBiXoa);
      senDataToSQLAndDel(maTheBiXoa);
    }

    if (mathe.startsWith("Quet the ")) {
      String maTheDuocQuet = mathe.substring(9); // tách số từ vị trí 15 của chuỗi và chuyển thành số nguyên
      Serial.print("\nDa nhan ma the duoc quet: ");
      Serial.println(maTheDuocQuet);
      sendDataHistoryToSQLAndAdd(maTheDuocQuet, "B");
    }

    else {
      Serial.print("\nDa nhan ma the duoc them: ");
      Serial.println(mathe);
      sendDataToSQLAndAdd(mathe, "B");
    }
  }
  if (SIM800A.available())
  {
    NhanTinNhan();
  }

  getDataFromSQL();
}
