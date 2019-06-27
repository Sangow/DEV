<?php
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));

    if ($a > $b) {
        echo $a . PHP_EOL;
    } else {
        echo $b . PHP_EOL;
    }
?>