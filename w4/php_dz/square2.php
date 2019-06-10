<?php
    $size = rtrim(fgets(STDIN));
    $out = "";

    for ( $i = 0, $counter = 1, $lineSize = $size; $i < $size; $i++ ) {
        $out .= implode(range($counter, $lineSize), " ") . PHP_EOL;
        $counter += $size;
        $lineSize += $size;
    }
    echo $out;
?>