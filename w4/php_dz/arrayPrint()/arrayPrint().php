<?php
    function arrayPrint($out, $array, $size) {
        fwrite($out, implode($array, " ") . PHP_EOL);
    }

    $out = fopen("task.out", "w");
    $arr = (range(1, 10));

    arrayPrint($out, $arr, count($arr));
    fclose($out);
?>