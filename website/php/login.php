<form>
    <input type="text" name="username" id="username" placeholder="username" required>
    <input type="password" name="password" id="password" placeholder="password" required>
    <input type="submit" name="loginsend" id="loginsend" required>
</form>

<?php 

    if(issend($_POST['loginsend'])){
        echo "workin' bitches";
    }

?>