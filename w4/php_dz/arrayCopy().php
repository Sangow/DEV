<?php
    function arrayCopy(&$destination, &$source, $size) {
        foreach ($source as $value) {
            $destination[] = $value;
        }
    }
?>