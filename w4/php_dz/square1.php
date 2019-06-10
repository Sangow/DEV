<?php
    $size = rtrim(fgets(STDIN));
    $out = "";

    for ( $row = 1; $row <= $size; $row++ ) {
        for ( $col = 1; $col < $size; $col++ ) {
            $out .= $col . " ";
        }
        $out .= $size . PHP_EOL;
    }
    echo $out;
?>