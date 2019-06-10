<?php
    $last = trim(fgets(STDIN));

    echo implode(range(1, $last), " ") . PHP_EOL;
?>