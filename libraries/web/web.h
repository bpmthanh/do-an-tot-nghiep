const char webpage[] PROGMEM = R"=====(


<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, width=device-width">
    <title>Smart Lock</title>
    <link rel="stylesheet" href="https://cdn.materialdesignicons.com/6.5.95/css/materialdesignicons.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

    <style>
        body {
            background-color: #e3edf7;
            font-family: Poppins;
        }

        #sha_app {
            padding: 20px 7px;
        }

        /** Start Section Header Bar Style **/
        #sha_header_bar {
            color: rgba(49, 69, 106, 0.6);
        }

        #sha_header_bar span {
            display: block;
        }

        #sha_header_bar span.sub-heading {
            font-size: 30px;
            font-weight: 500;
            padding-top: 10px;
        }

        #sha_header_bar span.heading {
            color: rgba(49, 69, 106, 1);
            font-size: 25px;
            font-weight: 600;
            margin-top: -5px;
        }

        /** End Section Header Bar Style **/

        /** Start Section Button List Style **/
        #sha_button_list {
            margin-top: 10px;
        }

        #sha_button_list ul {
            padding: 0;
        }

        #sha_button_list ul li {
            list-style: none;
            float: left;
            width: 20%;
            text-align: center;
            padding: 10px 0;
        }

        #sha_button_list ul li:first-child {
            margin-left: -5px;
        }

        #sha_button_list ul li span {
            display: inline-block;
            width: 50px;
            height: 50px;
            line-height: 50px;
            border-radius: 15px;
        }

        #sha_button_list ul li.off span {
            color: rgba(49, 69, 106, 0.35);

            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);

            border: 1px solid rgba(0, 0, 0, 0.0);
        }

        #sha_button_list ul li.on span {
            color: rgba(49, 69, 106, 1);

            box-shadow: inset 4px 4px 6px -1px rgba(0, 0, 0, 0.2),
                inset -4px -4px 6px -1px rgba(255, 255, 255, 0.7),
                -0.5px -0.5px 0 rgba(255, 255, 255, 1),
                0.5px 0.5px 0 rgba(0, 0, 0, 0.15),
                0px 12px 10px -10px rgba(0, 0, 0, 0.05);
            border: 1px solid rgba(0, 0, 0, 0.01);
        }

        /** End Section Button List Style **/

        /** Start Section Body 1 Style **/
        #sha_temp_body {
            text-align: center;
            margin-top: 30px;
        }

        #sha_temp_body .sha_temp {
            position: relative;
            display: inline-block;
            width: 230px;
            height: 230px;
            border-radius: 100%;
            text-align: center;
            box-shadow: 30px 30px 30px -10px rgba(0, 0, 0, 0.1),
                -30px -30px 30px -10px rgba(255, 255, 255, 0.4),
                -0.5px -0.5px 0 rgba(255, 255, 255, 1),
                0.5px 0.5px 0 rgba(0, 0, 0, 0.02);
        }

        #sha_temp_body .sha_temp>span {
            position: relative;
            display: inline-block;
            top: 50%;
            transform: translateY(-60%);
        }

        #sha_temp_body .sha_temp>span>span.temp-data {
            font-size: 60px;
            font-weight: 600;
            display: block;
            color: rgba(49, 69, 106, 1);
        }

        #sha_temp_body .sha_temp>span>span.temp-data sup {
            position: absolute;
            font-size: 15px;
            font-weight: 500;
            top: 24%;
        }

        #sha_temp_body .sha_temp>span>span.temp-info {
            position: absolute;
            font-size: 14px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.6);
            white-space: nowrap;
            bottom: -10px;
            left: 50%;
            transform: translateX(-50%);
        }

        #sha_temp_body .sha_temp:before {
            position: absolute;
            content: '';
            display: block;
            width: 88%;
            height: 88%;
            border-radius: inherit;
            left: 50%;
            top: 50%;
            transform: translateX(-50%) translateY(-50%);
            box-shadow: inset 4px 4px 6px -1px rgba(0, 0, 0, 0.2),
                inset -4px -4px 6px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_body .sha_temp:after {
            position: absolute;
            content: '';
            display: block;
            width: 78%;
            height: 78%;
            border-radius: inherit;
            left: 50%;
            top: 50%;
            background-color: rgba(0, 0, 0, 0.025);
            border: 1px solid rgba(0, 0, 0, 0.01);
            transform: translateX(-50%) translateY(-50%);
            box-shadow: inset 4px 4px 6px -1px rgba(0, 0, 0, 0.2),
                inset -4px -4px 6px -1px rgba(255, 255, 255, 0.7);
        }

        /** End Section Body 1 Style **/

        /** Start Section Body 2 Style **/
        #sha_temp_meta_1 {
            margin-top: 30px;
        }

        #sha_temp_meta_1 .sha_tile>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_1 .sha_tile>div span.tile_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            color: rgba(49, 69, 106, 0.6);
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_1 .sha_tile>div span.tile_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.8);
            padding-left: 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_1 .sha_tile>div span.tile_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_temp_meta_1 .sha_tile:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 2 Style **/



        /** Start Section Body 3 Style **/

        #sha_temp_meta_2 {
            margin-top: 30px;
        }

        #sha_temp_meta_2 .sha_tile>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_2 .sha_tile>div span.tile_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            color: rgba(49, 69, 106, 0.6);
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_2 .sha_tile>div span.tile_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.8);
            padding-left: 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_2 .sha_tile>div span.tile_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_temp_meta_2 .sha_tile:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 3 Style **/



        /** Start Section Body 4 Style **/

        #sha_temp_meta_3 {
            margin-top: 30px;
        }

        #sha_temp_meta_3 .sha_tile>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_3 .sha_tile>div span.tile_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            color: rgba(49, 69, 106, 0.6);
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_3 .sha_tile>div span.tile_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.8);
            padding-left: 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_3 .sha_tile>div span.tile_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_temp_meta_3 .sha_tile:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 4 Style **/



        /** Start Section Body 5 Style **/

        #sha_temp_meta_4 {
            margin-top: 30px;
        }

        #sha_temp_meta_4 .sha_tile>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_4 .sha_tile>div span.tile_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            color: rgba(49, 69, 106, 0.6);
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_4 .sha_tile>div span.tile_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.8);
            padding-left: 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_4 .sha_tile>div span.tile_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_temp_meta_4 .sha_tile:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 5 Style **/



        /** Start Section Footer Style **/
        #sha_footer {
            margin-top: 15px;
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_footer .footer_title {
            font-size: 15px;
            display: block;
        }

        #sha_footer .footer_data {
            font-size: 18px;
            font-weight: 500;
            color: rgba(49, 69, 106, 1);
        }

        #sha_footer .footer_data span {
            color: rgba(49, 69, 106, 0.5);
        }

        #sha_footer .sha_switch {
            position: relative;
            display: inline-block;
            width: 60px;
            height: 30px;
            border-radius: 25px;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 255, 0, 0.6);
            box-shadow: inset 4px 4px 8px rgba(0, 0, 0, 0.15);
            margin-top: 2px;
        }

        #sha_footer .sha_switch:before {
            content: '';
            position: absolute;
            width: 30px;
            height: 26px;
            background-color: #e3edf7;
            border-radius: 12px;
            right: 1px;
            top: 1px;
            box-shadow: 0px 2px 4px 1px rgba(0, 0, 0, 0.15);
        }

        /** End Section Footer Style **/


        .container {
            color: rgba(49, 69, 106, 1);
            font-size: 25px;
            font-weight: 600;
            /* margin-top: 45px; */
        }

        .container th {
            font-size: 16px;
            font-weight: 500;
            color: rgba(49, 69, 106, 0.8);
        }

        .container td {
            font-size: 16px;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.5);
        }

        #dangnhap {
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
        }

        #dangnhap span,
        #dangnhap b {
            /* Đặt màu cho các phần tử span và b bên trong div dangnhap */
            color: rgba(49, 69, 106, 1);
        }


        table {
            width: 100%;
            max-width: 400px;
        }

        th {
            text-align: center;
        }

        td {
            padding: 10px;
        }

        input {
            width: 100%;
            box-sizing: border-box;
        }

        .checkbox-container {
            display: flex;
            align-items: center;
        }

        .checkbox-container input[type="checkbox"] {
            margin-right: 5px;
        }

        .history-user-camera {
            display: flex;
            flex-direction: column;
        }

        .history-user-camera a:nth-child(2) {
            color: red;
        }


        @media (max-width: 600px) {
            td {
                padding: 5px;
            }

            th {
                font-size: 14px;
            }

            td,
            input {
                font-size: 16px;
            }

            .button-container {
                text-align: center;
            }
        }
    </style>

</head>


<script>
    const $ = document.querySelector.bind(document);
    const $$ = document.querySelectorAll.bind(document);

    setInterval(function () {
        //location.reload();
    }, 2000);

    // Lấy đối tượng span
    var subHeading = document.querySelector('.sub-heading');

    // Tạo đối tượng Date để lấy ngày tháng hiện tại
    var today = new Date();

    // Format ngày tháng theo định dạng: dd MMM yyyy
    var formattedDate = today.getDate() + ' ' + (today.toLocaleString('default', {
        month: 'short'
    })) + ' ' + today.getFullYear();

    // Gán giá trị ngày tháng vào thẻ span
    subHeading.innerHTML = formattedDate;


    function GetButtonData(data) {
        switch (data) {

            case 3:
                console.log("OnClick Mo cua");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/mocua", true);
                xhttp.send();
                break;
            case 4:
                console.log("OnClick 1 LOP");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/1lop", true);
                xhttp.send();
                break;
            case 5:
                console.log("OnClick 2 lop");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/2lop", true);
                xhttp.send();
                break;
            case 6:
                console.log("OnClick doi mat khau");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/doimatkhau", true);
                xhttp.send();
                break;
            case 7:
                console.log("themthe");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/themthe", true);
                xhttp.send();
                break;
            case 8:
                console.log("xoathe");

                var xhttp = new XMLHttpRequest();
                xhttp.open("GET", "/xoathe", true);
                xhttp.send();
                break;
        }
    }

    function toggleClass(element) {
        var liElement = element.parentNode;
        // Kiểm tra xem class "on" có đang được áp dụng cho thẻ "li" không
        var isOn = liElement.classList.contains('on');

        // Lấy danh sách tất cả các thẻ "li" trong danh sách
        var liElements = element.parentNode.parentNode.getElementsByTagName("li");
        for (var i = 0; i < liElements.length; i++) {
            // Nếu thẻ "span" được click nằm trong thẻ "li" khác và class "on" đang được áp dụng,
            // thì chuyển class "on" thành "off"
            if (liElements[i] !== liElement && liElements[i].classList.contains('on')) {
                liElements[i].classList.remove('on');
                liElements[i].classList.add('off');
            }
        }

        // Nếu class "on" chưa được áp dụng cho thẻ "li", thì thêm class "on"
        if (!isOn) {
            liElement.classList.add('on');
            liElement.classList.remove('off');
        }

        for (var i = 0; i < liElements.length; i++) {
            if (liElements[i].classList.contains('on')) {
                var listTableI = $(`#sha_temp_meta_${i + 1}`);
                listTableI.classList.remove('d-none');
            }
            if (liElements[i].classList.contains('off')) {
                var listTableI = $(`#sha_temp_meta_${i + 1}`);
                listTableI.classList.add('d-none');
            }
        }

    }


    function myFunction() {
        var x = document.getElementById("pass");
        if (x.type === "password") {
            x.type = "text";
        } else {
            x.type = "password";
        }
    }


    function login() {
        var ssid = document.getElementById("ssid").value;
        var pass = document.getElementById("pass").value;

        if (ssid == "1" && pass == "1") {
            console.log("OK");
            document.getElementById("ssid").value = "";
            document.getElementById("pass").value = "";
            document.getElementById("dangnhap").style.display = "none";


            document.getElementById("dieukhien").style.display = "block";

        }
        else {
            console.log("Error!!!");
            document.getElementById("ssid").value = "";
            document.getElementById("pass").value = "";
            alert("Tên đăng nhập hoặc mật khẩu không đúng vui lòng kiểm tra lại!!!");
        }
    }


    function Start() {
        myFunction();
    }

</script>

<body onload="Start()">

    <div id="content">

        <div id="dangnhap" style="display: block;">
            <table border="2" cellpadding="10">
                <tr>
                    <th colspan="2">
                        <center>
                            <font size="5"> <span> Đăng nhập </span></font>
                        </center>
                    </th>
                </tr>
                <tr>
                    <td>
                        <center> <span> <b> Tên đăng nhập</b> </span> </center>
                    </td>
                    <td align="center">
                        <input id="ssid" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <center> <span> <b> Mật khẩu</b> </span> </center>
                    </td>
                    <td align="center">
                        <div class="checkbox-container">
                            <input id="pass" />
                            <input type="checkbox" onclick="myFunction()" checked />
                        </div>
                    </td>
                </tr>
                <tr>
                    <td colspan="2">
                        <center> <span> <b> Xác nhận </b> </span> </center>
                    </td>
                </tr>
                <tr>
                    <td colspan="2">
                        <div class="button-container">
                            <input class="button_quaylai" type="button" onclick="login()" value="ĐỒNG Ý" />
                        </div>
                    </td>
                </tr>
            </table>
        </div>

        <div id="dieukhien" style="display: none;">
            <div class="container-fluid">

                <div id="sha_app" class="row">

                    <!-- Start Section Header Bar -->
                    <section id="sha_header_bar" class="col-12">
                        <div class="row">
                            <!-- <div class="col-12">
                        <i class="fa fa-chevron-left"></i>
                    </div> -->
                            <div class="col-12">
                                <!-- <span class="sub-heading"></span> -->
                                <span class="heading">Smart Lock</span>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Header Bar -->

                    <!-- Start Section Button List -->
                    <section id="sha_button_list" class="col-12">
                        <div class="row">
                            <div class="col-12">
                                <ul class="header-navigation">
                                    <li class="on">
                                        <span onclick="toggleClass(this)">
                                            <i class="fa fa-home"></i>
                                        </span>
                                    </li>
                                    <li class="off">
                                        <span onclick="toggleClass(this)">
                                            <i class="mdi mdi-account-multiple"></i>
                                        </span>
                                    </li>
                                    <li class="off">
                                        <span onclick="toggleClass(this)">
                                            <i class="mdi mdi-account-switch"></i>
                                        </span>
                                    </li>
                                    <li class="off">
                                        <span onclick="toggleClass(this)">
                                            <i class="fa fa-camera"></i>
                                        </span>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Button List -->

                    <!-- Start Section Body 1 -->
                    <!-- <section id="sha_temp_body" class="col-12">
                    <div class="row">
                        <div class="col-12">
                            <span class="sha_temp">
                                <span>
                                    <span class="temp-data">
                                        16 <sup>&deg;C</sup>
                                        <i class="fa fa-lock"></i>
                                    </span>
                                    <span class="temp-info">
                                        <i class="fa fa-snowflake-o"></i> Cooling
                                    </span>
                                </span>
                            </span>
                        </div>
                    </div>
                </section> -->
                    <!-- End Section Body 1 -->

                    <!-- Start Section Body 2 -->
                    <section id="sha_temp_meta_1" class="col-12">
                        <div class="row">
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(4)>
                                        <i class="mdi mdi-cards-outline"></i>
                                    </span>
                                    <span class="tile_info">
                                        Chế độ bảo mật 1 lớp
                                        <span>Mở khóa cửa bằng thẻ điện tử</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(5)>
                                        <i class="mdi mdi-lock"></i>
                                    </span>
                                    <span class="tile_info">
                                        Chế độ bảo mật 2 lớp
                                        <span>Mở khóa cửa bằng thẻ điện tử và mật khẩu</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(3)>
                                        <i class="mdi mdi-door-open"></i>
                                    </span>
                                    <span class="tile_info">
                                        Mở cửa
                                        <span>Mở khóa cửa từ xa qua thông qua một lần nhấn nút</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(6)>
                                        <i class="mdi mdi-lock-plus-outline"></i>
                                    </span>
                                    <span class="tile_info">
                                        Đổi mật khẩu
                                        <span>Thay đổi mật khẩu khóa cửa</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(7)>
                                        <i class="mdi mdi-smart-card"></i>
                                    </span>
                                    <span class="tile_info">
                                        Thêm thẻ
                                        <span>Thêm một người dùng thông qua thẻ điện tử</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(8)>
                                        <i class="mdi mdi-smart-card-off"></i>
                                    </span>
                                    <span class="tile_info">
                                        Xóa thẻ
                                        <span>Xóa một người dùng thông qua thẻ điện tử</span>
                                    </span>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 2 -->

                    <!-- Start Section Body 3 -->
                    <section id="sha_temp_meta_2" class="col-12 d-none">
                        <div class="row">
                            <div class="col-12 sha_tile">
                                <div class="container">
                                    <h2>Danh sách người dùng</h2>
                                    <iframe src="https://finalfeteliotproject.000webhostapp.com/index.php" width="100%"
                                        height="300" scrolling="yes" frameborder="0"></iframe>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 3 -->

                    <!-- Start Section Body 4 -->
                    <section id="sha_temp_meta_3" class="col-12 d-none">
                        <div class="row">
                            <div class="col-12 sha_tile">
                                <div class="container">
                                    <h2>Lịch sử người dùng</h2>
                                    <iframe
                                        src="https://finalfeteliotproject.000webhostapp.com/history_client_index.php"
                                        width="100%" height="300" scrolling="yes" frameborder="0"></iframe>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 4 -->

                    <!-- Start Section Body 4 -->
                    <section id="sha_temp_meta_4" class="col-12 d-none">
                        <!-- <div class="row">
                            <div class="col-12 sha_tile">
                                <div class="container">
                                    <div class="history-user-camera">
                                        <a href="https://drive.google.com/drive/folders/14sAAgFctTbna1vD6l3EvPGXoNimZ0e2_?hl=vi"
                                            target="_blank">Lịch sử người dùng hợp lệ</a>
                                        <a href="https://drive.google.com/drive/folders/1WKU3QXEy03a_yObKKoqZC-OEPrALVs8y?hl=vi"
                                            target="_blank">Lịch sử người dùng không hợp lệ</a>
                                    </div>
                                </div>
                            </div>
                        </div> -->
                        <div class="row">
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(4)>
                                        <i class="mdi mdi-account-star"></i>
                                    </span>
                                    <span class="tile_info">
                                        Lịch sử người dùng hợp lệ
                                        <span><a href="https://drive.google.com/drive/folders/14sAAgFctTbna1vD6l3EvPGXoNimZ0e2_?hl=vi" target="_blank">Xem chi tiết</a></span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_tile">
                                <div>
                                    <span class="tile_icon" onclick=GetButtonData(5)>
                                        <i class="mdi mdi-account-off"></i>
                                    </span>
                                    <span class="tile_info">
                                        Lịch sử người dùng không hợp lệ
                                        <span><a href="https://drive.google.com/drive/folders/1WKU3QXEy03a_yObKKoqZC-OEPrALVs8y?hl=vi" target="_blank">Xem chi
                                                tiết</a></span>
                                    </span>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 4 -->

                    <!-- Start Section Footer -->
                    <!-- <section id="sha_footer" class="col-12">
                        <div class="row">
                            <div class="col-8">
                                <div>
                                    <span class="footer_title">
                                        Current Temperature
                                    </span>
                                    <span class="footer_data">
                                        18.5 <span class="unit">&deg;C</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-4">
                                <div>
                                    <span class="footer_title text-right">
                                        Turn On/Off
                                    </span>
                                    <span class="footer_data">
                                        <span class="sha_switch pull-right"></span>
                                    </span>
                                </div>
                            </div>
                        </div>
                    </section> -->
                    <!-- End Section Footer -->
                </div>

            </div>
        </div>

    </div>



</body>

</html>

)=====";