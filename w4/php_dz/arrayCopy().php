<?php
    function arrayCopy(&$destination, &$source, $size) {
        // foreach ($source as $value) {
        //     $destination[] = $value;
        // }

        for ( $i = 0; $i < $size; $i++ ) {
            $destination[$i] = $source[$i];
        }
    }

    $source = range(1, 5);
    $dest = array();

    arrayCopy($dest, $source, 5);

    print_r($dest)
?>