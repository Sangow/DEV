<?php
    $value = trim(fgets(STDIN));
    $flag = 1;

    if ( $value % 2 == 0 ) {
        $flag = 0;
        echo "alpha" . PHP_EOL;
    }
    if ( $value % 3 == 0 ) {
        $flag = 0;
        echo "bravo" . PHP_EOL;
    }
    if ( $value % 5 == 0 ) {
        $flag = 0;
        echo "charie" . PHP_EOL;
    }
    if ( $flag ) {
        echo "zulu" . PHP_EOL;
    }
?>