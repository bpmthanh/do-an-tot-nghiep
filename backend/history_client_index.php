<!DOCTYPE html>
<html>
   <head>
      <style>
         #customers {
         font-family: Arial, Helvetica, sans-serif;
         border-collapse: collapse;
         width: 100%;
         }
         #customers td, #customers th {
         border: 1px solid #ddd;
         padding: 8px;
         }
         #customers tr:nth-child(even){background-color: #f2f2f2;}
         #customers tr:hover {background-color: #ddd;}
         #customers th {
         padding-top: 12px;
         padding-bottom: 12px;
         text-align: left;
         background-color: #FF0000;
         color: white;
         }
      </style>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/xmlhttprequest/2.0.0/xmlhttprequest.min.js"></script>
   </head>
   <script>
      function deleteRow(btn) {
      var row = btn.closest('tr');
      var id = row.cells[0].innerHTML;
      var xhr = new XMLHttpRequest();
      xhr.open("POST", "history_client_index.php", true);
      xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      xhr.onreadystatechange = function() {
      if (xhr.readyState == 4 && xhr.status == 200) {
      row.parentNode.removeChild(row);
      }
      };
      
      // Sử dụng trường "action" với giá trị "delete" để phân biệt yêu cầu xóa
      xhr.send("id=" + id + "&action=delete");
      }
      
      
       
      function editRow(id, currentName, currentLocation) {
      var nameField = document.getElementById('name_' + id);
      var locationField = document.getElementById('location_' + id);
      var actionButtons = document.getElementById('action_buttons_' + id);
      
      // Hiển thị các ô nhập liệu để chỉnh sửa
      nameField.innerHTML = '<input type="text" id="name_input_' + id + '" value="' + currentName + '">';
      locationField.innerHTML = '<input type="text" id="location_input_' + id + '" value="' + currentLocation + '">';
      
      // Tạo nút "Lưu"
      var saveButton = document.createElement('button');
      saveButton.innerHTML = 'Lưu';
      
      // Đặt sự kiện onclick cho nút "Lưu"
      saveButton.onclick = function() {
      // Lấy giá trị đã chỉnh sửa
      var newName = document.getElementById('name_input_' + id).value;
      var newLocation = document.getElementById('location_input_' + id).value;
      
      var xhr = new XMLHttpRequest();
      xhr.open("POST", "history_client_index.php", true);
      xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      xhr.onreadystatechange = function() {
      if (xhr.readyState == 4 && xhr.status == 200) {
        // Cập nhật nội dung trong ô Tên người dùng và Địa điểm
        nameField.innerHTML = newName;
        locationField.innerHTML = newLocation;
      
        // Đổi nút "Lưu" thành nút "Chỉnh sửa"
        actionButtons.replaceChild(editButton, saveButton);
      }
      };
      
      // Sử dụng trường "action" để phân biệt yêu cầu cập nhật và yêu cầu xóa
      xhr.send("id=" + id + "&action=update&name=" + newName + "&location=" + newLocation);
      };
      
      // Lấy nút "Chỉnh sửa" trong actionButtons
      var editButton = actionButtons.querySelector('button:nth-child(2)');
      
      // Chèn nút "Lưu" vào container actionButtons
      actionButtons.appendChild(saveButton);
      }
      
      
      
       
          
   </script>
   <body>
      <?php
         error_reporting(0);
         
         $servername = "localhost";
         $username = "id20685249_admin";
         $password = "ThanhPro@1023";
         $dbname = "id20685249_dataclient";
         
         // Create connection
         $conn = new mysqli($servername, $username, $password, $dbname);
         // Check connection
         if ($conn->connect_error) {
             die("Connection failed: " . $conn->connect_error);
         }
         
         if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $id = $_POST["id"];
         $action = $_POST["action"];
         
         if ($action == "update") {
         $newName = $_POST["name"];
         $newLocation = $_POST["location"];
         
         $sql = "UPDATE historydetail SET name='$newName', location='$newLocation' WHERE id = '$id'";
         
         if ($conn->query($sql) === TRUE) {
            echo "Cập nhật dữ liệu thành công";
         } else {
            echo "Error updating record: " . $conn->error;
         }
         } 
         
         else if ($action == "delete") {
         $sql = "DELETE FROM historydetail WHERE id = '$id'";
         
         if ($conn->query($sql) === TRUE) {
            echo "Xóa dữ liệu thành công";
         } else {
            echo "Error deleting record: " . $conn->error;
         }
         }
         }
         
         
         // Truy vấn và hiển thị dữ liệu từ cơ sở dữ liệu
         $sql = "SELECT id, name, location, time FROM historydetail ORDER BY id DESC";
         echo '<table cellspacing="5" cellpadding="5" id="customers">
             <thead>
                 <tr>
                     <th>ID</th>
                     <th>Tên người dùng</th>
                     <th>Địa điểm</th>
                     <th>Thời gian</th>
                     <th>Xóa</th>
                 </tr>
             </thead>';
         
         if ($result = $conn->query($sql)) {
             while ($row = $result->fetch_assoc()) {
                 $row_id = $row["id"];
                 $row_name = $row["name"];
                 $row_location = $row["location"];
                 $row_reading_time = $row["time"];
         
                 echo '<tr> 
                     <td>' . $row_id . '</td> 
                     <td id="name_' . $row_id . '">' . $row_name . '</td> 
                     <td id="location_' . $row_id . '">' . $row_location . '</td> 
                     <td>' . $row_reading_time . '</td>
                     <td>
                         <div id="action_buttons_' . $row_id . '">
                             <button onclick="deleteRow(this)">Xóa</button>
                             <!-- <button onclick="editRow(' . $row_id . ', \'' . $row_name . '\', \'' . $row_location . '\')">Chỉnh sửa</button> -->
                         </div>
                     </td>
                 </tr>';
             }
             $result->free();
         }
         
         $conn->close();
         ?>
   </body>
</html>