<?php
    $dividend = rtrim(fgets(STDIN));
    $divisor = abs(rtrim(fgets(STDIN)));

    $prevMultiple = $dividend - $dividend % $divisor;

    if ( $prevMultiple > $dividend ) {
        $prevMultiple -= $divisor;
    }

    echo $prevMultiple . PHP_EOL;
?>