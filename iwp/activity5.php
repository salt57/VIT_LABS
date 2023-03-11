<?php
print_r($_FILES);
$allowedExts = array("gif", "jpeg", "jpg", "png");
$temp = explode(".", $_FILES["file"]["name"]);
$extension = end($temp);
$upload_dir = "Saved_File";
if (
    (($_FILES["file"]["type"] == "image/gif")
        || ($_FILES["file"]["type"] == "image/jpeg")
        || ($_FILES["file"]["type"] == "image/jpg")
        || ($_FILES["file"]["type"] == "image/pjpeg")
        || ($_FILES["file"]["type"] == "image/x-png")
        || ($_FILES["file"]["type"] == "image/png"))
    && ($_FILES["file"]["size"] < 500000)
    && in_array($extension, $allowedExts)
) {
    if ($_FILES["file"]["error"] > 0) {
        echo "Return Code: " . $_FILES["file"]["error"] . "<br>";
    } else {
        echo "Upload: " . $_FILES["file"]["name"] . "<br>";
        echo "Type: " . $_FILES["file"]["type"] . "<br>";
        echo "Size: " . ($_FILES["file"]["size"] / 1024) . " kB<br>";
        echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br>";
        $name = $_FILES['file']['name'];
        if (file_exists("$upload_dir/$name")) {
            echo $_FILES["file"]["name"] . " already exists. ";
        } else {
            if (
                move_uploaded_file(
                    $_FILES["file"]["tmp_name"],
                    "$upload_dir/$name"
                )
            ) {

                echo "Stored in: " . "Saved_File/" . $_FILES["file"]["name"];
            } else {
                echo "unable to upload file";
                echo $_FILES["file"]["error"];
            }
        }
    }
} else {
    echo "Invalid file";
}
?>