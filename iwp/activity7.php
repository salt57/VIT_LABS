<?php
$servername = "localhost";
$username = "salt57";
$password = "Sg2002";
$dbname = "activities";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM activity7";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<style> 
            .background {
                content: '';
                background-image: url('/images/vit.jpeg');
                background-repeat: no-repeat;
                background-position: center center;
                background-size: cover;
                background-size: cover;
                position: absolute;
                top: 0px;
                right: 0px;
                bottom: 0px;
                left: 0px;
                opacity: 0.25;
                z-index: -1;
            }
            th {
              background-color: #ccc;
            }
            td {
                background-color: white;
            }
            table, th, td {
                border: 1px solid black;
                border-collapse: collapse;
            }
            .main_heading {
                margin-top: 150px;
                color: green;
                font-size: 60px;
            }
            .sub_heading {
                color: blue;
                font-size: 60px;
            }
            th, td, table, h1 {
                opacity: 1;
            }
          </style>
          <div class='background'></div>
          <center class='container'>
          <h1 class='main_heading'>CAT EXAM PROCESS</h1>
          <h1 class='sub_heading'>SCOPE</h1>
          <h1 class='sub_heading' style='font-size: 50px;'>VIT UNIVERSITY, VELLORE</h1>
          <table>
            <tr>
              <th>Course Code</th>
              <th>Course Name</th>
              <th>Faculty ID</th>
              <th>Reg. Number</th>
              <th>Student Name</th>
              <th>Faculty Name</th>
              <th>Student Branch</th>
              <th>Status</th>
              <th>Course Type</th>
            </tr>";
    foreach ($result as $row) {
        echo "<tr><td>" . $row["coursecode"] . "</td><td>" . $row["coursename"] . "</td><td>" . $row["facultyid"] . "</td><td>" . $row["regnum"] . "</td><td>" . $row["studentname"] . "</td><td>" . $row["facultyname"] . "</td><td>" . $row["studentbranch"] . "</td><td>" . $row["status"] . "</td><td>" . $row["coursetype"] . "</td></tr>";
    }
    echo "</table></center>";
} else {
    echo "0 results";
}
$conn->close();
?>