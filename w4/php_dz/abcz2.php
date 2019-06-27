<?php
    $value = rtrim(fgets(STDIN));
    $isZulu = true;

    if ( $value % 2 == 0 ) {
        $isZulu = false;
        echo "alpha" . PHP_EOL;
    }
    if ( $value % 3 == 0 ) {
        $isZulu = false;
        echo "bravo" . PHP_EOL;
    }
    if ( $value % 5 == 0 ) {
        $isZulu = false;
        echo "charie" . PHP_EOL;
    }
    if ( $isZulu ) {
        echo "zulu" . PHP_EOL;
    }
?>