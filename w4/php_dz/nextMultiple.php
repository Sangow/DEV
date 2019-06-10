<?php
    $dividend = rtrim(fgets(STDIN));
    $divisor = abs(rtrim(fgets(STDIN)));

    $nextMultiple = $dividend - $dividend % $divisor;

    if ( $nextMultiple < $dividend ) {
        $nextMultiple += $divisor;
    }

    echo $nextMultiple . PHP_EOL;
?>