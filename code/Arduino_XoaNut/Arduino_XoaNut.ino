

#include<DS1307RTC.h>
#include <DS1307.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <DS1307RTC.h>
#include <Arduino.h>
#include "DS1307.h"
#include <Eeprom24Cxx.h>
#include "Wire.h"
#include "I2CKeyPad.h"
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <avr/wdt.h>


SoftwareSerial esp (6, 7);
//SoftwareSerial SerialUART(2, 3); // RX: D2, TX: D3
#define RST_PIN         8
#define SS_PIN          10
LiquidCrystal_I2C lcd(0x27, 16, 2); // địa chỉ i2c của lcd là 0x27, 16 dòng 2 cột
RTC_DS1307 rtc;
DS1307 clock;


const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keyPad(KEYPAD_ADDRESS);
MFRC522 mfrc522(SS_PIN, RST_PIN);

int fid;
String ten;

int startaddrcard = 2;
int addrendaddrcard = 900;
int startaddrpass = 1010; // địa chỉ bắt đầu của mảng char mật khẩu
int addrnumkey = 1005; // địa chỉ lưu số kí tự trong mật khẩu
int addrcheDoMocua = 200; // địa chỉ lưu số kí tự trong mật khẩu

uint8_t index;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
long last = millis();
int kiemtra1;
char keys[] = "123A456B789C*0#DNF";  // N = NoKey, F = Fail
int Num_Key = 0, Dem_Pass = 0;


int  ktra ;
int menu = 4;
int demtong = 0;
int soLuongUser;
int Mode = 0, n = 0, k;
uint32_t m;
int time1 = 0, time2 = 0, time3 = 0;
char c[6], d[6];
byte chuoi[16];
int ID;
int dulieu = 0;
String mathe;
char chedomocua = 0;
int suco = 0;
String chuoithe;
int UID[4], i;
void ThemThe();
void XoaThe();
void DoiMatKhau();



int* dataArray = NULL;
int indexData = 0;
int sizeDataArray = 0;


void Out()
{
  lcd.clear();
  demtong = 0;
  Mode = 0;
  Time();
}


void MaHoaString()
{
  chuoithe = "";
  for (int i = 0; i < 4; i++)
  {
    chuoithe += (String)UID[i];
  }
  Serial.print("Ma hoa string: ");
  Serial.println(chuoithe);
}



void  MaHoa()
{
  ID = 0;
  int m = 25;
  for (int i = 0; i < 4; i++)
  {
    ID += UID[i] * m;
    m -= 3;
  }
  Serial.print("\nMa the sau khi ma hoa: ");
  Serial.println(ID);
}



int quetthe(long thoigian)
{
  //  Serial.print("\nBat dau quet the: ");
  long l = millis();
  while (1)
  {
    while ( ! mfrc522.PICC_IsNewCardPresent())
    {
      if (millis() - l > thoigian) {
        Serial.print("\n");
        return 0 ;
      }
    }
    while ( ! mfrc522.PICC_ReadCardSerial())
    {
      if (millis() - l > thoigian)
        return 0 ;
    }


    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      //      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      UID[i] = mfrc522.uid.uidByte[i];
      //      Serial.print(UID[i]);
    }
    MaHoa();
    //    MaHoaString();
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    return 1;
  }
}


void uint32_tToByte()
{
  //  esp.println(chuoithe);
  //  Serial.print("Da gui: ");
  //  Serial.println(chuoithe);
  Bao();
}




int Check_Key(int diaChiBatDau, int diaChiSoKyTu)
{
  char a[5];

  //  unsigned long startTime = millis();
  //  unsigned long duration = 0;
  //  const unsigned long TIMEOUT = 4000;

  while (Num_Key < 6)
  {
    // Kiểm tra thời gian trôi qua
    //    duration = millis() - startTime;

    // Kiểm tra nếu đã trôi qua 4 giây
    //    if (duration >= TIMEOUT)
    //    {
    //      resetFunc(); // Reset lại Arduino
    //    }

    index = keyPad.getKey();
    if (keys[index] != 'N' && keys[index] != 'F')
    {
      lcd.setCursor((0 + Num_Key), 1);
      delay(100);
      lcd.print("*");
      delay(150);
      a[Num_Key++] = keys[index];
    }
  }



  for (int i = 0; i <= sizeof(a) / sizeof(a[0]); i++) {
    Serial.print(a[i] - 48);
  }
  Serial.println();



  Num_Key = 0;
  int j;
  k = 0;
  for (j = diaChiBatDau; j < diaChiBatDau + 6; j++)
  {
    if (AVR_EEPROM.read_1_byte(j) != a[k] - 48)
    {
      return 0;
    }
    k++;
  }
  return 1;
}





void Time()
{
  DateTime now = rtc.now();
  lcd.setCursor(0, 1);
  if (now.hour() <= 9)
  {
    lcd.print("0");
    lcd.print(now.hour());
  }
  else {
    lcd.print(now.hour());
  }
  lcd.print(':');
  if (now.minute() <= 9)
  {
    lcd.print("0");
    lcd.print(now.minute());
  }
  else {
    lcd.print(now.minute());
  }
  lcd.print(':');
  if (now.second() <= 9)
  {
    lcd.print("0");
    lcd.print(now.second());
  }
  else {
    lcd.print(now.second());
  }
  lcd.print("   ");
  lcd.setCursor(0, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(",");
  if (now.day() <= 9)
  {
    lcd.print("0");
    lcd.print(now.day());
  }
  else {
    lcd.print(now.day());
  }
  lcd.print('/');
  if (now.month() <= 9)
  {
    lcd.print("0");
    lcd.print(now.month());
  }
  else {
    lcd.print(now.month());
  }
  lcd.print('/');
  if (now.year() <= 9)
  {
    lcd.print("0");
    lcd.print(now.year());
  }
  else {
    lcd.print(now.year());
  }
}



int Check_Card(int id, int a, int b)
{
  lcd.clear();
  int i;
  for (i = b; i <= AVR_EEPROM.read_2_byte(a); i += 2)
  {
    if (AVR_EEPROM.read_2_byte(i) == id)
    {
      return 1;
    }
  }
  return 0;
}



void SPAM(int c)
{
  if (c == 0)
  {
    digitalWrite(A1, 1);
    delay(100);
    digitalWrite(A1, 0);
  }
  else
  {
    digitalWrite(A1, 1);
    delay(1000);
    digitalWrite(A1, 0);
  }
}


unsigned int Gia_tri_moi;
void setup1()
{
  TCCR1A = 0;
  TCCR1B = 0;
  // RESET lại 2 thanh ghi
  DDRB |= (1 << PB1);
  // Đầu ra PB0 là OUTPUT ( pin 8)

  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  // chọn Fast PWM, chế độ chọn TOP_value tự do  ICR1
  TCCR1A |= (1 << COM1A1);
  // So sánh thường( none-inverting)

  TCCR1B |= (1 << CS11);
  // P_clock=16mhz/8=2mhz
  // mỗi P_clock bằng 1/2mhz= 0.5 us
  OCR1A = 1060;
  Gia_tri_moi = OCR1A;
  // Value=1060 , tương đương xung có độ rộng 1060*0.5us=530us (0.53ms)
  // Value=4820, tương đương xung có độ rộng 4820*0.5us=2410us (2,41ms)
  ICR1 = 40000;
  // xung răng cưa tràn sau 40000 P_clock, tương đương (20ms)
}



void Bao()
{
  digitalWrite(A0, 1);
  delay(100);
  digitalWrite(A0, 0);
}



void set(unsigned int x)
{
  if (Gia_tri_moi != x) {
    OCR1A = x;
    Gia_tri_moi = OCR1A;
  }
  else {
    return; // thoát ngay
  }
  // x : 1060 - 4820
  //Độ rộng: 0.53ms - 2.41 ms
}




void DoiMatKhau()
{
  Dem_Pass = 0;
  //  unsigned long startTime = millis();
  while (Dem_Pass < 2)
  {
    lcd.clear();
    lcd.print("MAT KHAU MOI");

    lcd.setCursor(0, 1);
    m = 0;
    while (m < 6)
    {
      //      unsigned long duration = millis() - startTime;
      // Kiểm tra nếu đã trôi qua 4 giây
      //      if (duration >= 4000)
      //      {
      //        resetFunc(); // Reset lại Arduino
      //      }
      index = keyPad.getKey();
      if (keys[index] != 'N' && keys[index] != 'F')
      {
        lcd.print(keys[index]);
        lcd.setCursor((0 + m), 1);
        delay(100);
        lcd.print("*");
        delay(150);
        c[m++] = keys[index];
      }
    }
    delay(100);
    m = 0;
    lcd.clear();
    lcd.print("XAC NHAN LAI");
    lcd.setCursor(0, 1);
    while (m < 6)
    {
      index = keyPad.getKey();
      if (keys[index] != 'N' && keys[index] != 'F')
      {
        lcd.print(keys[index]);
        lcd.setCursor((0 + m), 1);
        delay(100);
        lcd.print("*");
        delay(150);
        d[m++] = keys[index];
      }
    }
    n = 0;
    ktra = 0;

    for (k = 0; k < 6; k++)
    {
      if (c[k] != d[k])
      {
        n = 1;
        lcd.clear();
        lcd.print("KHONG TRUNG KHOP");
        Serial.println("WARNING!\n");
        SPAM(0);
        delay(1000);
        lcd.clear();
        ktra = 2;
        Dem_Pass++;
        resetFunc(); // Reset lại Arduino
        break;
      }
    }
    if (n == 0)
    {
      k = 0;
      for (m = startaddrpass; m < startaddrpass + 6; m++)
      {
        if (AVR_EEPROM.read_1_byte(m) != (c[k]) - 48)
        {
          ktra = 1;
          lcd.clear();
          lcd.print("HOAN THANH");
          delay(1000);
          for (k = 0; k < 6; k++)
          {
            AVR_EEPROM.write_1_byte(1010 + k, c[k] - 48);
          }
          Dem_Pass = 3;
          break;
        }
        k++;
      }
    }
    if (ktra == 0)
    {
      lcd.clear();
      lcd.print("PASS MOI GIONG");
      lcd.setCursor(0, 1);
      lcd.print("PASS CU");
      SPAM(0);
      delay(1000);
      lcd.clear();
      Dem_Pass++;
    }
  }
  resetFunc(); // Reset lại Arduino
}




void XoaThe()
{
  int dataArrayEEPROM[5];
  int indexDataArrayEEPROM = 0;
  if (startaddrcard == AVR_EEPROM.read_2_byte(addrendaddrcard))
  {
    lcd.clear();
    lcd.print("DANH SACH THE");
    lcd.setCursor(0, 1);
    lcd.print("DA TRONG");
    SPAM(0);
    delay(1000);
    Out();
  }
  else
  {
    while (1)
    {
      if (startaddrcard == AVR_EEPROM.read_2_byte(addrendaddrcard))
      {
        lcd.clear();
        lcd.print("DANH SACH THE");
        lcd.setCursor(0, 1);
        lcd.print("DA TRONG");
        SPAM(0);
        delay(1000);
        Out();
        break;
      }
      n = 0;
      lcd.clear();
      lcd.print("QUET THE CAN XOA");
      if (quetthe(4000) == 0)
      {
        Out();
        break;
      }
      lcd.clear();
      lcd.print("DANG XOA....");
      Delete_Card(ID, startaddrcard, addrendaddrcard);
      lcd.clear();
      lcd.print("DA XOA");
      delay(1000);
      lcd.clear();

      dataArrayEEPROM[indexDataArrayEEPROM] = ID; // Lưu ID vào mảng dataArray
      indexDataArrayEEPROM++; // Tăng indexData lên 1 để tránh ghi đè dữ liệu
    }

    for (int i = 0; i < indexDataArrayEEPROM; i++) {
      if (dataArrayEEPROM[i] != 0) {
        esp.println("Xoa the " + String(dataArrayEEPROM[i]));
        delay(200);
      }
    }
    Serial.print("Da gui ma the bi xoa len SQL");
  }
}

void Delete_Card(int a, int  b, int  c)
{
  int i, j, h = 1;
  //  if (a == AVR_EEPROM.read_2_byte(b) )
  //  {
  //    lcd.clear();
  //    lcd.print("KHONG THE XOA");
  //    delay(500);
  //    lcd.clear();
  //    return;
  //  }
  for (i = b; i <= AVR_EEPROM.read_2_byte(c); i += 2) // a = ID, b = địa chỉ bắt đầu, c = nơi lưu địa chỉ bắt đầu
  {
    if (AVR_EEPROM.read_2_byte(i) == a)
    {
      for (j = i; j < AVR_EEPROM.read_2_byte(c); j += 2)
      {
        AVR_EEPROM.write_2_byte(j, AVR_EEPROM.read_2_byte(j + 2) );
      }
      AVR_EEPROM.write_2_byte(c, (AVR_EEPROM.read_2_byte(c) - 2));
      h = 0;
      break;
    }
  }
  if (h == 1)
  {
    lcd.clear();
    lcd.print("THE KHONG TON TAI");
    delay(500);
  }
}



void resetFunc(void) {
  wdt_enable(WDTO_15MS);
  while (1) {}
}


void removeNonMatchingElements(int* dataArray, int& dataArraySize, int startaddrcard, int addrendaddrcard)
{

  for (int k = startaddrcard; k <= AVR_EEPROM.read_2_byte(addrendaddrcard); k += 2)
  {
    bool found = false;
    for (int i = 0; i < dataArraySize; i++) {
      if (dataArray[i] == AVR_EEPROM.read_2_byte(k)) {
        found = true;
        break;
      }
    }
    if (!found) {
      Delete_Card(AVR_EEPROM.read_2_byte(k), startaddrcard, addrendaddrcard);
    }
  }
  //  resetFunc();
}



void ThemThe()
{
  int dataArrayEEPROM[5];
  int indexDataArrayEEPROM = 0;

  while (1)
  {
    lcd.clear();
    lcd.print("QUET THE DE THEM");
    if (quetthe(4000) == 0)
    {
      Out();
      break;
    }
    lcd.clear();
    lcd.print("DANG THEM....");
    ktra = 1;
    for (k = startaddrcard; k <= AVR_EEPROM.read_2_byte(addrendaddrcard); k += 2)
    {
      if (ID == AVR_EEPROM.read_2_byte(k))
      {
        lcd.clear();
        lcd.print("THE DA TON TAI");
        delay(1000);
        lcd.clear();
        ktra = 0;
        break;
      }
    }
    if (ktra == 1)
    {
      AVR_EEPROM.write_2_byte(AVR_EEPROM.read_2_byte(addrendaddrcard), ID);
      AVR_EEPROM.write_2_byte(addrendaddrcard, AVR_EEPROM.read_2_byte(addrendaddrcard) + 2 );
      ktra = 0;

      dataArrayEEPROM[indexDataArrayEEPROM] = ID; // Lưu ID vào mảng dataArray
      indexDataArrayEEPROM++; // Tăng indexData lên 1 để tránh ghi đè dữ liệu

      lcd.clear();
      lcd.print("DA THEM");
      delay(1000);
      lcd.clear();
    }
  }
  for (int i = 0; i < indexDataArrayEEPROM; i++) {
    if (dataArrayEEPROM[i] != 0) {
      esp.println(dataArrayEEPROM[i]);
    }
  }
}



void setup()
{
  Serial.begin(19200);
  esp.begin(19200);
  //SerialUART.begin(19200);
  lcd.init();
  lcd.backlight();
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(menu, INPUT_PULLUP);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);



  // Xóa toàn bộ EEPROM
  //  for (int i = 0; i < EEPROM.length(); i++) {
  //    EEPROM.write(i, 0);
  //  }

  // Đọc và in giá trị lưu trong EEPROM từ địa chỉ 0 đến 255
  //  Serial.print("\n");
  //  for (int i = 1005; i <= 1024; i++) {
  //    byte value = EEPROM.read(i);
  //    Serial.print("EEPROM[");
  //    Serial.print(i);
  //    Serial.print("] = ");
  //    Serial.println(value);
  //  }


  if (!rtc.isrunning()) {
    Serial.println("RTC không hoạt động! Đang thiết lập thời gian ban đầu...");

    // Đặt thời gian ban đầu của RTC bằng thời gian hiện tại
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }


}


void loop()
{
  unsigned long lastGetDataTime = 0;

  if (digitalRead(menu) == 0)
  {
    delay(50);
    if (digitalRead(menu) == 0)
    {
      while (digitalRead(menu) == 0);
      if (Mode == 0)
      {
        Mode = 1;
      }
      else
      {
        Mode = 0;
      }
    }
  }

  if (Mode == 0)
  {
    Time();

    if (esp.available())
    {
      Bao(); // có dữ liệu
      mathe = esp.readStringUntil('\n');


      if (mathe.startsWith("So luong user: ")) {
        soLuongUser = mathe.substring(15).toInt();
        Serial.print("\n\nSo luong user: ");
        Serial.println(soLuongUser);
      }

      if (mathe.toInt() != 0 || soLuongUser == 0) {
        dulieu = mathe.toInt();
        Serial.print("Da nhan du lieu la: ");
        Serial.println(dulieu);

        if (dulieu > 1000 || (soLuongUser == 0 && dulieu == 0)) {

          if (indexData >= sizeDataArray) {
            // Nếu mảng đã đầy thì tăng kích thước mảng lên gấp đôi
            sizeDataArray = (sizeDataArray == 0) ? 1 : sizeDataArray * 2;
            dataArray = (int*) realloc(dataArray, sizeDataArray * sizeof(int));

            if (dataArray == NULL) {
              // Nếu không tăng được kích thước mảng thì xử lý lỗi
              Serial.println("Error: Unable to allocate memory");
              return;
            }
          }
          dataArray[indexData] = dulieu;
          indexData++;

          if (soLuongUser == 0) {
            AVR_EEPROM.write_2_byte(startaddrcard, 0 );
            AVR_EEPROM.write_2_byte(addrendaddrcard, 0);
            indexData = 0;
          }


          if (indexData == soLuongUser) {
            for (int i = startaddrcard; i <= addrendaddrcard; i++) {
              AVR_EEPROM.write_2_byte(i, 0); // ghi giá trị vào địa chỉ EEPROM
            }

            int addr = startaddrcard; // địa chỉ EEPROM ban đầu
            for (int i = 0; i < indexData; i++) {
              AVR_EEPROM.write_2_byte(addr, dataArray[i]); // ghi giá trị vào địa chỉ EEPROM
              addr += 2; // tăng địa chỉ lên 2 byte để ghi giá trị tiếp theo vào địa chỉ tiếp theo
            }
            // Lưu địa chỉ kết thúc vào EEPROM
            AVR_EEPROM.write_2_byte(addrendaddrcard, addr);
            indexData = 0;
          }


        }
      }

      if (dulieu == 8)
      {
        chedomocua = 1;
        AVR_EEPROM.write_2_byte(addrcheDoMocua, chedomocua);
        dulieu = 0;
      }
      if (dulieu == 7)
      {
        chedomocua = 0;
        AVR_EEPROM.write_2_byte(addrcheDoMocua, chedomocua);
        dulieu = 0;
      }
      if (dulieu == 9)
      {
        // digitalWrite(A0,1);
        setup1();
        set(4200); // 90 độ
        delay(2000);
        // digitalWrite(A0,0);
        set(2200); // 0 độ
        dulieu = 0;
        Serial.println("OPENED!\n");

      }
      if (dulieu == 10)
      {
        DoiMatKhau();
        dulieu = 0;
      }
      if (dulieu == 11)
      {
        ThemThe();
        dulieu = 0;
      }
      if (dulieu == 12)
      {
        XoaThe();
        dulieu = 0;
      }
    }
  }

  if (Mode == 1)
  {
    int ktra1, Dem_Card = 0;
    while (Dem_Card < 2)
    {
      lcd.clear() ;
      lcd.print("QUET THE");
      if (quetthe(4000) == 0)
      {
        Out();
        break;
      }
      if (Check_Card(ID, addrendaddrcard , startaddrcard ) == 1)
      {
        ktra1 = 0;
        delay(500);
        while (Dem_Pass < 2)
        {
          if (AVR_EEPROM.read_2_byte(addrcheDoMocua) == 1)
          {
            lcd.clear();
            Dem_Pass = 0;
            lcd.clear();
            lcd.print("MAT KHAU DUNG");
            lcd.setCursor( 0, 1);
            lcd.print("WELCOME");
            uint32_tToByte();

            setup1();
            set(4200); // 90 độ
            delay(2000);
            set(2200); // 0 độ
            Serial.println("OPENED!\n");
            lcd.clear();
            kiemtra1 == 1;
            break;
            ktra = 1;
          }

          if (AVR_EEPROM.read_2_byte(addrcheDoMocua) == 0) 
          {
            lcd.clear();
            lcd.print("NHAP MAT KHAU");
            lcd.setCursor(4, 1);
            int checkKey = Check_Key(startaddrpass, addrnumkey);
            if (checkKey == 1)
            {
              lcd.clear();
              Dem_Pass = 0;
              lcd.clear();
              lcd.print("MAT KHAU DUNG");
              lcd.setCursor( 0, 1);
              lcd.print("WELCOME");
              uint32_tToByte();

              setup1();
              set(4200); // 90 độ
              delay(2000);
              set(2200); // 0 độ
              Serial.println("OPENED!\n");
              lcd.clear();
              kiemtra1 == 1;
              break;
              ktra = 1;
            }
            else
            {
              SPAM(0);
              Dem_Pass++;
              lcd.clear();
              if (Dem_Pass > 1)
              {
                if (AVR_EEPROM.read_2_byte(startaddrcard) == ID)
                {
                  Dem_Pass = 9;
                  kiemtra1 = 1;
                  ktra1 = 1;
                  break;
                }
                //                else
                //                {
                //                  Delete_Card(ID, startaddrcard, addrendaddrcard);
                //                  Serial.println("Xoa the " + String(ID));
                //                  esp.println("Xoa the " + String(ID));
                //                  kiemtra1 = 1;
                //                  Dem_Pass = 9;
                //                  ktra1 = 1;
                //                  break;
                //                }
              }
            }
          }
        }
        if ( Dem_Pass == 9) // phat hien spam
        {
          esp.println("spam");
          Serial.println("WARNING!\n");
          Serial.print("Da gui: ");
          Serial.println("spam");
          Dem_Pass = 0;
          SPAM(1);
          Out();
        }
        Dem_Card = 3;
        esp.println("Quet the " + String(ID));
      }
      else
      {
        SPAM(0);
        Dem_Card++;
        if (Dem_Card > 1)
        {
          SPAM(1);
          Dem_Card = 9;
          esp.println("spam");
          Serial.println("WARNING!\n");
          Serial.print("Da gui: ");
          Serial.println("spam");
          Out();
          break;
        }
      }
    }
  }
}