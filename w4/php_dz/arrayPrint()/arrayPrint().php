<?php
    function arrayPrint(&$out, &$array) {
        fwrite($out, implode($array, " ") . PHP_EOL);
    }
?>