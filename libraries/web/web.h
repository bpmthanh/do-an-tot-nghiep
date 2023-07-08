const char webpage[] PROGMEM = R"=====( 


<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, width=device-width">
    <title>HỆ THỐNG CỬA BẢO MẬT</title>
    <link rel="stylesheet" href="https://cdn.materialdesignicons.com/6.5.95/css/materialdesignicons.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

    <style>
        @import url('https://fonts.googleapis.com/css?family=Baloo');

        /* html,
        body {
            height: 100%;
            width: 100%;
            font-family: 'Baloo', cursive;
            font-size: 1.5em;
            letter-spacing: .8px;
            color: tomato;
        } */

        body {
            /* background-color: #e3edf7; */
            background-color: #F6F8FA;
            font-family: Poppins;
        }

        #sha_app {
            /* padding: 20px 7px; */
        }

        .section-header {
            background-color: #fff;
            padding: 25px 20px;
            border: 1px solid #fff;
            border-radius: 0 0 45px 45px;
        }

        /** Start Section Header Bar Style **/
        #sha_header_bar {
            /* color: rgba(49, 69, 106, 0.6); */
            color: #000;
            display: flex;
            justify-content: space-between;
            align-items: flex-start;
        }

        #sha_header_bar .row:nth-child(2)>.col-12 {
            display: flex;
            flex-direction: column;
            align-items: end;
        }

        #sha_header_bar span {
            display: block;
        }

        #sha_header_bar span.sub-heading {
            font-size: 25px;
            font-weight: 500;
            padding-top: 10px;
        }

        #sha_header_bar span.heading {
            /* color: rgba(49, 69, 106, 1); */
            color: #1877f2;
            font-size: 35px;
            font-weight: 600;
            margin-top: -5px;
            /* border: 1px solid #26C4FA;
            width: fit-content;
            padding: 7px;
            border-radius: 20px; */
        }

        .feeling {
            font-family: 'Baloo', cursive;
            color: tomato;
            font-size: 30px;
            display: none;
        }

        .weather-font {
            margin-top: 20px;
            display: flex;
            align-items: center;
        }

        .weather-des {
            font-size: 30px;
            font-weight: bold;
            color: #000;
        }

        .weather-font img {
            width: 50px;
            margin-right: 10px;
        }

        /** End Section Header Bar Style **/

        /** Start Section Button List Style **/
        #sha_button_list {
            margin-top: 10px;
        }

        #sha_button_list ul {
            padding: 0;
            display: flex;
            justify-content: space-around;
            margin-top: 35px;
        }

        #sha_button_list ul li {
            list-style: none;
            float: left;
            text-align: center;
            padding: 10px 0;

            height: 100%;
            width: 100%;
            font-size: 1.5em;
            letter-spacing: .8px;
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
            /* color: rgba(49, 69, 106, 1); */
            color: #3976f6;

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
            display: flex;
            justify-content: space-around;
        }

        #sha_temp_body .sha_temp {
            position: relative;
            display: inline-block;
            width: 200px;
            height: 200px;
            border-radius: 100%;
            text-align: center;
            box-shadow: 30px 30px 30px -10px rgba(0, 0, 0, 0.1),
                -30px -30px 30px -10px rgba(255, 255, 255, 0.4),
                -0.5px -0.5px 0 rgba(255, 255, 255, 1),
                0.5px 0.5px 0 rgba(0, 0, 0, 0.02);
            background-color: #8263E5;
        }

        #sha_temp_body .sha_wind {
            background-color: #63dee5;
        }

        #sha_temp_body .sha_humid {
            background-color: #04295d;
        }

        #sha_temp_body .sha_temp>span {
            position: relative;
            display: inline-block;
            top: 50%;
            transform: translateY(-60%);
        }

        #sha_temp_body .sha_temp>span>span.temp-data,
        #sha_temp_body .sha_temp>span>span.wind-data,
        #sha_temp_body .sha_temp>span>span.humid-data {
            font-size: 30px;
            font-weight: 600;
            display: block;
            /* color: rgba(49, 69, 106, 1); */
            color: #fff;
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
            /* color: rgba(49, 69, 106, 0.6); */
            color: #fff;
            white-space: nowrap;
            bottom: -20px;
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

        #sha_temp_meta_1 .row,
        #sha_temp_meta_4 .row {
            display: grid;
            grid-template-columns: auto auto;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(1) div {
            background-color: #26C4FA;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(2) div {
            background-color: #ECB625;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(3) div {
            background-color: #1BB857;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(4) div {
            background-color: #8231FF;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(5) div {
            background-color: #DA522E;
        }

        #sha_temp_meta_1 .row .sha_title:nth-child(6) div {
            background-color: #24B2E4;
        }

        #sha_temp_meta_1 .sha_title>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_1 .sha_title>div .title_icon,
        #sha_temp_meta_4 .sha_title>div .title_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            border-radius: 15px;
            background-color: #fff;
            color: #000;
            /* box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
        -6px -6px 10px -1px rgba(255, 255, 255, 0.7); */
            transition: all 0.5s;
            cursor: pointer;
        }

        #sha_temp_meta_1 .sha_title>div span.title_icon.clicked,
        #sha_temp_meta_4 .sha_title>div span.title_icon.clicked {
            box-shadow: inset 4px 4px 6px -1px rgba(0, 0, 0, 0.2),
                inset -4px -4px 6px -1px rgba(255, 255, 255, 0.7),
                -0.5px -0.5px 0 rgba(255, 255, 255, 1),
                0.5px 0.5px 0 rgba(0, 0, 0, 0.15),
                0px 12px 10px -10px rgba(0, 0, 0, 0.05);
            border: 1px solid rgba(0, 0, 0, 0.01);
            color: #fff;
            background-color: #3976f6;
        }


        #sha_temp_meta_1 .sha_title>div span.title_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #fff;
            padding: 0 14px;
        }

        #sha_temp_meta_1 .sha_title>div span.title_info span {
            display: block;
            font-weight: 400;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #fff;
        }

        #sha_temp_meta_1 .sha_title:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 2 Style **/



        /** Start Section Body 3 Style **/

        #sha_temp_meta_2 {
            margin-top: 30px;
        }

        #sha_temp_meta_2 .sha_title>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_2 .sha_title>div span.title_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            /* color: rgba(49, 69, 106, 0.6); */
            color: #000;
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_2 .sha_title>div span.title_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #000;
            padding: 0 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_2 .sha_title>div span.title_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.8);
        }

        #sha_temp_meta_2 .sha_title:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 3 Style **/



        /** Start Section Body 4 Style **/

        #sha_temp_meta_3 {
            margin-top: 30px;
        }

        #sha_temp_meta_3 .sha_title>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_3 .sha_title>div span.title_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            /* color: rgba(49, 69, 106, 0.6); */
            color: #000;
            box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7);
        }

        #sha_temp_meta_3 .sha_title>div span.title_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #000;
            padding: 0 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_3 .sha_title>div span.title_info span {
            display: block;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.8);
        }

        #sha_temp_meta_3 .sha_title:not(last-child) {
            margin-bottom: 12px;
        }

        /** End Section Body 4 Style **/



        /** Start Section Body 5 Style **/

        #sha_temp_meta_4 {
            margin-top: 30px;
        }


        #sha_temp_meta_4 .sha_title>div {
            position: relative;
            border: 1px solid rgba(255, 255, 255, 0.7);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            border-radius: 15px;
            padding: 22px;
            box-shadow: 15px 5px 20px -10px rgba(0, 0, 0, 0.15),
                -15px -5px 20px -10px rgba(255, 255, 255, 0.8);
        }

        #sha_temp_meta_4 .sha_title>div span.title_icon {
            display: inline-block;
            width: 60px;
            height: 60px;
            text-align: center;
            line-height: 60px;
            font-size: 20px;
            border-radius: 15px;
            border: 1px solid rgba(0, 0, 0, 0.02);
            background-color: rgba(0, 0, 0, 0.01);
            background-color: #fff;
            /* color: rgba(49, 69, 106, 0.6); */
            color: #000;
            /* box-shadow: 6px 6px 10px -1px rgba(0, 0, 0, 0.15),
                -6px -6px 10px -1px rgba(255, 255, 255, 0.7); */
        }

        #sha_temp_meta_4 .sha_title>div span.title_info {
            position: absolute;
            display: inline-block;
            font-size: 16px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #fff;
            padding: 0 14px;
            margin-top: 5px;
        }

        #sha_temp_meta_4 .sha_title>div span.title_info span a {
            display: block;
            font-weight: 400;
            color: blue;
            /* color: #fff; */
        }

        #sha_temp_meta_4 .sha_title:not(last-child) {
            margin-bottom: 12px;
        }

        #sha_temp_meta_4 .row .sha_title:nth-child(1) div {
            background-color: #1BB857;
        }

        #sha_temp_meta_4 .row .sha_title:nth-child(2) div {
            background-color: red;
        }

        /** End Section Body 5 Style **/



        /** Start Section Footer Style **/
        #sha_footer {
            margin-top: 15px;
            color: rgba(49, 69, 106, 0.8);
        }

        #sha_footer .footer_title {
            font-size: 15px;
            display: block;
        }

        #sha_footer .footer_data {
            font-size: 18px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 1); */
            color: #3976f6;
        }

        #sha_footer .footer_data span {
            color: rgba(49, 69, 106, 0.8);
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
            /* color: rgba(49, 69, 106, 1); */
            color: #000;
            font-size: 25px;
            font-weight: 600;
        }

        .container th {
            font-size: 16px;
            font-weight: 500;
            /* color: rgba(49, 69, 106, 0.8); */
            color: #000;
        }

        .container td {
            font-size: 16px;
            font-weight: 400;
            color: rgba(49, 69, 106, 0.8);
        }

        #dangnhap {
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
        }

        #dangnhap span,
        #dangnhap b {
            /* color: rgba(49, 69, 106, 1); */
            color: #3976f6;
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



        /* login */
        @import url("https://fonts.googleapis.com/css2?family=Poppins:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: "Poppins", sans-serif;
            background: #f2f4f7;
        }

        .content {
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
        }

        .flex-div {
            display: flex;
            justify-content: space-evenly;
            align-items: center;
        }

        .name-content {
            margin-right: 7rem;
        }

        .name-content .logo {
            font-size: 3.5rem;
            color: #1877f2;
        }

        .name-content p {
            font-size: 1.3rem;
            font-weight: 500;
            margin-bottom: 5rem;
        }

        form {
            display: flex;
            flex-direction: column;
            background: #fff;
            padding: 2rem;
            width: 530px;
            height: 300px;
            border-radius: 0.5rem;
            box-shadow: 0 2px 4px rgb(0 0 0 / 10%), 0 8px 16px rgb(0 0 0 / 10%);
        }

        form input {
            outline: none;
            padding: 0.8rem 1rem;
            margin-bottom: 0.8rem;
            font-size: 1.1rem;
        }

        form input:focus {
            border: 1.8px solid #1877f2;
        }

        form .login {
            outline: none;
            border: none;
            background: #1877f2;
            padding: 0.8rem 1rem;
            border-radius: 0.4rem;
            font-size: 1.1rem;
            color: #fff;
        }

        form .login:hover {
            background: #0f71f1;
            cursor: pointer;
        }

        form a {
            text-decoration: none;
            text-align: center;
            font-size: 1rem;
            padding-top: 0.8rem;
            color: #1877f2;
        }

        form hr {
            background: #f7f7f7;
            margin: 1rem;
        }

        form .create-account {
            outline: none;
            border: none;
            background: #06b909;
            padding: 0.8rem 1rem;
            border-radius: 0.4rem;
            font-size: 1.1rem;
            color: #fff;
            width: 75%;
            margin: 0 auto;
        }

        form .create-account:hover {
            background: #03ad06;
            cursor: pointer;
        }

        /* //.........Media Query.........// */

        @media (max-width: 500px) {
            html {
                font-size: 60%;
            }

            .name-content {
                margin: 0;
                text-align: center;
            }

            form {
                width: 300px;
                height: fit-content;
            }

            form input {
                margin-bottom: 1rem;
                font-size: 1.5rem;
            }

            form .login {
                font-size: 1.5rem;
            }

            form a {
                font-size: 1.5rem;
            }

            form .create-account {
                font-size: 1.5rem;
            }

            .flex-div {
                display: flex;
                flex-direction: column;
            }
        }

        @media (min-width: 501px) and (max-width: 768px) {
            html {
                font-size: 60%;
            }

            .name-content {
                margin: 0;
                text-align: center;
            }

            form {
                width: 300px;
                height: fit-content;
            }

            form input {
                margin-bottom: 1rem;
                font-size: 1.5rem;
            }

            form .login {
                font-size: 1.5rem;
            }

            form a {
                font-size: 1.5rem;
            }

            form .create-account {
                font-size: 1.5rem;
            }

            .flex-div {
                display: flex;
                flex-direction: column;
            }
        }

        @media (min-width: 769px) and (max-width: 1200px) {
            html {
                font-size: 60%;
            }

            .name-content {
                margin: 0;
                text-align: center;
            }

            form {
                width: 300px;
                height: fit-content;
            }

            form input {
                margin-bottom: 1rem;
                font-size: 1.5rem;
            }

            form .login {
                font-size: 1.5rem;
            }

            form a {
                font-size: 1.5rem;
            }

            form .create-account {
                font-size: 1.5rem;
            }

            .flex-div {
                display: flex;
                flex-direction: column;
            }

            @media (orientation: landscape) and (max-height: 500px) {
                .header {
                    height: 90vmax;
                }
            }
        }






        @media (max-width: 768px) {

            #sha_temp_meta_1 .row,
            #sha_temp_meta_4 .row {
                display: initial;
            }

            .feeling {
                font-size: 20px;
            }

            #sha_temp_body {
                display: none;
            }

            .feeling {
                display: none;
            }

            .weather-des {
                display: none !important;
            }
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

    document.addEventListener("DOMContentLoaded", function () {
        var subHeading = document.querySelector('.sub-heading');
        var today = new Date();
        var formattedDate = 'Ngày ' + today.getDate() + ' tháng ' + (today.getMonth() + 1) + ' năm ' + today.getFullYear();
        subHeading.innerHTML = formattedDate;
    });


    function GetButtonData(data, event) {

        var button = event.target;
        if (button.tagName === 'I') {
            button = button.parentElement; // Lấy phần tử cha (<span>)
        }
        if (button) {
            button.classList.add("clicked");
            setTimeout(function () {
                button.classList.remove("clicked");
            }, 400);
        }

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


    document.addEventListener("DOMContentLoaded", function () {
        // Lấy danh sách các phần tử chứa nhiệt độ
        var temperatureSpans = document.getElementsByClassName("temp-data");
        var windSpans = document.getElementsByClassName("wind-data");
        var humidSpans = document.getElementsByClassName("humid-data");

        // Tạo đối tượng XMLHttpRequest
        var xhr = new XMLHttpRequest();

        // Định nghĩa hàm xử lý khi yêu cầu hoàn thành
        xhr.onreadystatechange = function () {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    // Lấy nhiệt độ từ kết quả trả về
                    var response = JSON.parse(xhr.responseText);
                    var hcmTemperature = response.main.temp;
                    var hcmWind = response.wind.speed;
                    var hcmHumid = response.main.humidity;
                    var weatherStatus = response.weather[0].main;

                    // Cập nhật giá trị nhiệt độ HCM cho tất cả các phần tử
                    for (var i = 0; i < temperatureSpans.length; i++) {
                        temperatureSpans[i].innerHTML = hcmTemperature + ' <sup>&deg;C</sup>';
                    }
                    for (var i = 0; i < windSpans.length; i++) {
                        windSpans[i].innerHTML = hcmWind + ' km/h';
                    }
                    for (var i = 0; i < humidSpans.length; i++) {
                        humidSpans[i].innerHTML = hcmHumid + ' %';
                    }
                } else {
                    console.log("Error: " + xhr.status);
                }
            }
        };

        // Gửi yêu cầu GET đến API để lấy nhiệt độ HCM
        xhr.open('GET', 'https://api.openweathermap.org/data/2.5/weather?q=Ho%20Chi%20Minh%20City&appid=cd645c85dd9c540d68e5a0c19af66a0b&units=metric', true);
        xhr.send();
    });



</script>

<body onload="Start()">

    <div id="content">

        <!-- <div id="dangnhap" style="display: block;">
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
        </div> -->
        <div class="content" id="dangnhap" style="display: block;">
            <div class="flex-div">
                <div class="name-content">
                    <h1 class="logo">HỆ THỐNG CỬA BẢO MẬT</h1>
                    <p>Lựa chọn bảo mật và an toàn dành cho bạn.!</p>
                </div>
                <form>
                    <input type="text" placeholder="Tên đăng nhập" required id="ssid" />
                    <input type="password" placeholder="Mật khẩu" required id="pass">
                    <button class="login" onclick="login()">Đăng nhập</button>
                    <!-- <a href="#">Forgot Password ?</a>
                    <hr>
                    <button class="create-account">Create New Account</button> -->
                </form>
            </div>
        </div>




        <div id="dieukhien" style="display: none;">
            <div class="container-fluid">

                <div id="sha_app" class="row">

                    <div class="section-header">
                        <!-- Start Section Header Bar -->
                        <section id="sha_header_bar" class="col-12">
                            <div class="row">
                                <div class="col-12">
                                    <span class="heading">HỆ THỐNG CỬA BẢO MẬT</span>
                                </div>
                                <div class="col-12">
                                    <span class="sub-heading">26 JAN 2020</span>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col-12">
                                    <div class="feeling"> Ngày hôm nay của bạn thế nào?</>
                                    </div>
                                    <div class="col-12 weather-font">
                                        <img src="https://creazilla-store.fra1.digitaloceanspaces.com/icons/7911203/weather-icon-md.png"
                                            alt="">
                                        <span class="weather-des">Mây, thành phố Hồ Chí Minh</span>
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
                        <section id="sha_temp_body" class="col-12">
                            <div class="row">
                                <div class="col-12">
                                    <span class="sha_temp">
                                        <span>
                                            <span class="temp-data">
                                                Loading...
                                            </span>
                                            <span class="temp-info">
                                                <i class="fa fa-snowflake-o"></i> Nhiệt độ
                                            </span>
                                        </span>
                                    </span>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col-12">
                                    <span class="sha_temp sha_wind">
                                        <span>
                                            <span class="wind-data">
                                                Loading...
                                            </span>
                                            <span class="temp-info">
                                                <i class="fa fa-snowflake-o"></i> Tốc độ gió
                                            </span>
                                        </span>
                                    </span>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col-12">
                                    <span class="sha_temp sha_humid">
                                        <span>
                                            <span class="humid-data">
                                                Loading...
                                            </span>
                                            <span class="temp-info">
                                                <i class="fa fa-snowflake-o"></i> Độ ẩm
                                            </span>
                                        </span>
                                    </span>
                                </div>
                            </div>
                        </section>
                        <!-- End Section Body 1 -->
                    </div>

                    <!-- Start Section Body 2 -->
                    <section id="sha_temp_meta_1" class="col-12">
                        <div class="row">
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(4,event)>
                                        <i class="mdi mdi-cards-outline"></i>
                                    </span>
                                    <span class="title_info">
                                        CHẾ ĐỘ BẢO MẬT 1 LỚP
                                        <span>Mở khóa cửa bằng thẻ điện tử</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(5,event)>
                                        <i class="mdi mdi-lock"></i>
                                    </span>
                                    <span class="title_info">
                                        CHẾ ĐỘ BẢO MẬT 2 LỚP
                                        <span>Mở khóa cửa bằng thẻ điện tử và mật khẩu</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(3,event)>
                                        <i class="mdi mdi-door-open"></i>
                                    </span>
                                    <span class="title_info">
                                        MỞ CỬA
                                        <span>Mở khóa cửa từ xa qua thông qua một lần nhấn nút</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(6,event)>
                                        <i class="mdi mdi-lock-plus-outline"></i>
                                    </span>
                                    <span class="title_info">
                                        ĐỔI MẬT KHẨU
                                        <span>Thay đổi mật khẩu khóa cửa</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(7,event)>
                                        <i class="mdi mdi-smart-card"></i>
                                    </span>
                                    <span class="title_info">
                                        THÊM THẺ
                                        <span>Thêm một người dùng thông qua thẻ điện tử</span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(8,event)>
                                        <i class="mdi mdi-smart-card-off"></i>
                                    </span>
                                    <span class="title_info">
                                        XÓA THẺ
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
                            <div class="col-12 sha_title">
                                <div class="container">
                                    <h2>DANH SÁCH NGƯỜI DÙNG</h2>
                                    <iframe src="https://hcmusiotproject.000webhostapp.com/index.php" width="100%"
                                        height="420" scrolling="yes" frameborder="0"></iframe>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 3 -->

                    <!-- Start Section Body 4 -->
                    <section id="sha_temp_meta_3" class="col-12 d-none">
                        <div class="row">
                            <div class="col-12 sha_title">
                                <div class="container">
                                    <h2>LỊCH SỬ NGƯỜI DÙNG</h2>
                                    <iframe src="https://hcmusiotproject.000webhostapp.com/history_client_index.php"
                                        width="100%" height="420" scrolling="yes" frameborder="0"></iframe>
                                </div>
                            </div>
                        </div>
                    </section>
                    <!-- End Section Body 4 -->

                    <!-- Start Section Body 4 -->
                    <section id="sha_temp_meta_4" class="col-12 d-none">
                        <!-- <div class="row">
                            <div class="col-12 sha_title">
                                <div class="container">
                                    <div class="history-user-camera">
                                        <a href="https://drive.google.com/drive/folders/14sAAgFctTbna1vD6l3EvPGXoNimZ0e2_?hl=vi"
                                            target="_blank">LỊCH SỬ NGƯỜI DÙNG HỢP LỆ</a>
                                        <a href="https://drive.google.com/drive/folders/1WKU3QXEy03a_yObKKoqZC-OEPrALVs8y?hl=vi"
                                            target="_blank">LỊCH SỬ NGƯỜI DÙNG KHÔNG  HỢP LỆ</a>
                                    </div>
                                </div>
                            </div>
                        </div> -->
                        <div class="row">
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(null,event)>
                                        <i class="mdi mdi-account-star"></i>
                                    </span>
                                    <span class="title_info">
                                        LỊCH SỬ NGƯỜI DÙNG HỢP LỆ
                                        <span><a href="https://drive.google.com/drive/folders/14sAAgFctTbna1vD6l3EvPGXoNimZ0e2_?hl=vi"
                                                target="_blank">Xem chi tiết</a></span>
                                    </span>
                                </div>
                            </div>
                            <div class="col-12 sha_title">
                                <div>
                                    <span class="title_icon" onclick=GetButtonData(null,event)>
                                        <i class="mdi mdi-account-off"></i>
                                    </span>
                                    <span class="title_info">
                                        LỊCH SỬ NGƯỜI DÙNG KHÔNG HỢP LỆ
                                        <span><a href="https://drive.google.com/drive/folders/1WKU3QXEy03a_yObKKoqZC-OEPrALVs8y?hl=vi"
                                                target="_blank">Xem chi tiết</a></span>
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