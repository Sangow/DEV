<?php
    list($a, $b, $c) = explode(' ', trim(fgets(STDIN)));

    echo max($a, $b, $c) . PHP_EOL;
?>