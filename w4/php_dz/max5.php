<?php 
    list($a, $b, $c, $d, $e) = explode(' ', trim(fgets(STDIN)));

    echo max($a, $b, $c, $d, $e) . PHP_EOL;
?>