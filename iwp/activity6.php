<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Define regular expression patterns
    $username_pattern = "/^[a-zA-Z0-9_-]{3,16}$/";
    $email_pattern = "/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $password_pattern = "/^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*()_+{}|:<>?]).{8,}$/";
    $name_pattern = "/^[a-zA-Z ]*$/";
    $nickname_pattern = "/^[a-zA-Z0-9_-]{3,16}$/";
    $website_pattern = "/^(http|https):\/\/[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,}([a-zA-Z0-9\/\?#=&_\-\.]*)$/";
    $jabber_pattern = "/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $aim_pattern = "/^[a-zA-Z0-9]{4,}$/";
    $yahoo_pattern = "/^[a-zA-Z0-9]{4,}$/";

    // Retrieve user input
    $username = $_POST["username"];
    $email = $_POST["email"];
    $password = $_POST["password"];
    $confirm_password = $_POST["confirm_password"];
    $display_name = $_POST["display_name"];
    $name_first = $_POST["name_first"];
    $name_last = $_POST["name_last"];
    $nickname = $_POST["nickname"];
    $website = $_POST["website"];
    $bio = $_POST["bio"];
    $jabber = $_POST["jabber"];
    $aim = $_POST["aim"];
    $yahoo = $_POST["yahoo"];

    // Validate fields
    $errors = array();

    if (!preg_match($username_pattern, $username)) {
        $errors["username"] = "Invalid username format. Must be between 3-16 characters and only contain letters, numbers, underscores, and hyphens.";
    }

    if (!preg_match($email_pattern, $email)) {
        $errors["email"] = "Invalid email format.";
    }

    if (!preg_match($password_pattern, $password)) {
        $errors["password"] = "Invalid password format. Must be at least 8 characters and contain at least one lowercase letter, one uppercase letter, one digit, and one special character.";
    }

    if ($password !== $confirm_password) {
        $errors["confirm_password"] = "Passwords do not match.";
    }

    if (!preg_match($name_pattern, $display_name)) {
        $errors["display_name"] = "Invalid display name format. Only letters and spaces are allowed.";
    }
    if (!preg_match($name_pattern, $name_first)) {
        $errors["name_first"] = "Invalid first name format. Only letters and spaces are allowed.";
    }
    if (!preg_match($name_pattern, $name_last)) {
        $errors["name_last"] = "Invalid last name format. Only letters and spaces are allowed.";
    }

    if (!preg_match($nickname_pattern, $nickname)) {
        $errors["nickname"] = "Invalid nickname format. Must be between 3-16 characters and only contain letters, numbers, underscores, and hyphens.";
    }

    if (!empty($website) && !preg_match($website_pattern, $website)) {
        $errors["website"] = "Invalid website format.";
    }

    if (!empty($jabber) && !preg_match($jabber_pattern, $jabber)) {
        $errors["jabber"] = "Invalid Jabber format.";
    }

    if (!empty($aim) && !preg_match($aim_pattern, $aim)) {
        $errors["aim"] = "Invalid AOL IM format. Must be at least 4 characters and only contain letters and numbers.";
    }

    if (!empty($yahoo) && !preg_match($yahoo_pattern, $yahoo)) {
        $errors["yahoo"] = "Invalid Yahoo IM format. Must be at least 4 characters and only contain letters and numbers.";
    }

    // If there are no errors, proceed with registration
    if (empty($errors)) {
        echo "Registration successful!";
    }
}
?>
<style>
    td {
        padding: 10px 10px;
        empty-cells: show;
    }

    label {
        font-weight: bold;
        margin-right: 20px;
    }

    input {
        height: 30px;
    }

    textarea {
        height: 100px;
    }

    button {
        background-color: #65B9E1;
        border: none;
        border-radius: 3px;
        padding: 5px;
        height: 40px;
        width: 200px;
        margin-top: 30px;
        color: white;
        font-weight: bold;
        cursor: pointer;
    }

    .btn-holder {
        width: 100%;
        display: flex;
        align-items: center;
        justify-content: center;
    }
</style>
<h1>Create User</h1>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    <table>
        <tr>
            <td colspan="1">
                <label>Username:</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="username" value="<?php echo htmlspecialchars($username); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["username"]))
                    echo $errors["username"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Email</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="email" name="email" value="<?php echo htmlspecialchars($email); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["email"]))
                    echo $errors["email"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Password</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="password" name="password">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["password"]))
                    echo $errors["password"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Confirm Password</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="password" name="confirm_password">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["confirm_password"]))
                    echo $errors["confirm_password"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Display Name</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="display_name" value="<?php echo htmlspecialchars($display_name); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["display_name"]))
                    echo $errors["display_name"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Name</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input placeholder="First" type="text" name="name_first"
                    value="<?php echo htmlspecialchars($name_first); ?>">
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input placeholder="Last" type="text" name="name_last"
                    value="<?php echo htmlspecialchars($name_last); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["name_last"]))
                    echo $errors["name_last"];
                if (!empty($errors["name_first"]))
                    echo $errors["name_first"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Nickname</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="nickname" value="<?php echo htmlspecialchars($nickname); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["nickname"]))
                    echo $errors["nickname"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Website</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="website" value="<?php echo htmlspecialchars($website); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["website"]))
                    echo $errors["website"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Bio</label>
            </td>
            <td colspan="2" style="vertical-align: middle; text-align:left;">
                <textarea style="width: 100%;" name="bio"><?php echo htmlspecialchars($bio); ?></textarea>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Jabber</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="jabber" value="<?php echo htmlspecialchars($jabber); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["jabber"]))
                    echo $errors["jabber"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>AOL IM</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="aim" value="<?php echo htmlspecialchars($aim); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["aim"]))
                    echo $errors["aim"]; ?>
            </td>
        </tr>
        <tr>
            <td colspan="1">
                <label>Yahoo IM</label>
            </td>
            <td colspan="1" style="vertical-align: middle; text-align:left;">
                <input type="text" name="yahoo" value="<?php echo htmlspecialchars($yahoo); ?>">
            </td>
            <td colspan="1">
                <?php if (!empty($errors["yahoo"]))
                    echo $errors["yahoo"]; ?>
            </td>
        </tr>
    </table>
    <div class="btn-holder">
        <button type="submit" name="submit">Create and Access</button>
    </div>
</form>