<?php
    list($a, $b, $c, $d) = explode(' ', trim(fgets(STDIN)));

    echo max($a, $b, $c, $d) . PHP_EOL;
?>