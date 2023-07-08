<?php
   $servername = "localhost";
   $username = "id20685249_admin";
   $password = "ThanhPro@1023";
   $dbname = "id20685249_dataclient";
   
   $api_key_value = "tPmAT5Ab3j7F8";
   $action_key_value = "delete";
   
   $api_key = $id = $name = $location = $action = "";
   
   
   if ($_SERVER["REQUEST_METHOD"] == "POST") {
   
   	  $api_key = test_input($_POST["api_key"]);
      $action_key = test_input($_POST["action"]);
   
           
        if($action_key == $action_key_value){
   
        $id = test_input($_POST["id"]);
   
   		// Create connection
   		$conn = new mysqli($servername, $username, $password, $dbname);
   		// Check connection
   		if ($conn->connect_error) {
   			die("Connection failed: " . $conn->connect_error);
   		}
   
   		// Insert data into the table
   		$sql = "DELETE FROM historydetail WHERE id='" . $id . "'";
           if ($conn->query($sql) === TRUE) {
               echo "Data deleted successfully";
           } else {
               echo "Error deleting record: " . $conn->error;
           }
   
           $conn->close();
            
      }
    
   	else if ($api_key == $api_key_value) {
   		$id = test_input($_POST["id"]);
   		$name = test_input($_POST["name"]);
   		$location = test_input($_POST["location"]);
   
   		// Create connection
   		$conn = new mysqli($servername, $username, $password, $dbname);
   		// Check connection
   		if ($conn->connect_error) {
   			die("Connection failed: " . $conn->connect_error);
   		}
   
   		// Insert data into the table
   		$sql = "INSERT INTO historydetail (id, name, location)
           VALUES ('" . $id . "', '" . $name . "', '" . $location . "')";
   
   		if ($conn->query($sql) === TRUE) {
   			echo "Data inserted successfully";
   		} else {
   			echo "Error: " . $sql . "<br>" . $conn->error;
   		}
   
   		$conn->close();
   	} else {
   		echo "Wrong API Key provided.";
   	}
   } 
   
   
   else if ($_SERVER["REQUEST_METHOD"] == "GET") {
	// tạo connection đến database
	$conn = new mysqli($servername, $username, $password, $dbname);
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	}

	// truy vấn tất cả các bản ghi trong bảng historydetail
	$sql = "SELECT * FROM historydetail";
	$result = $conn->query($sql);

	if ($result->num_rows > 0) {
		$data = array();
		while ($row = $result->fetch_assoc()) {
			$data[] = $row;
		}
		echo json_encode($data); // trả về kết quả dưới dạng JSON array
	} else {
		echo "No data found.";
	}

	$conn->close();
} 
   
   
   else {
   	echo "No data posted with HTTP POST.";
   }
   
   function test_input($data)
   {
   	$data = trim($data);
   	$data = stripslashes($data);
   	$data = htmlspecialchars($data);
   	return $data;
   }
   
