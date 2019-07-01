<?php
    function arrayScan(&$in, &$array, $limit) {
        $array = explode(' ', fread($in, $limit * 2));
    }

    $in = fopen("task.in", "r");

    $array = array();
    arrayScan($in, $array, 7);

    var_dump($array);

    fclose($in);
?>
