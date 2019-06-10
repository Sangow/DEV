<?php
    $size = rtrim(fgets(STDIN));
    $out = "";

    for ( $row = 1, $end = $size * $size, $start = $end - $size + 1; $row <= $size; $row++ ) {
        for ( $col = 1; $col < $size; $col++ ) {
            $out .= $start . " ";
            $start += 1;
        }
        $out .= $end . PHP_EOL;
        $end -= $size;
        $start = $end - $size + 1;
    }

    echo $out;
?>