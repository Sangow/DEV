<?php
    function gcd($a, $b) {
        if ( $b == 0 ) {
            return $a;
        }
        return gcd($b, $a % $b);
    }

    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");

    $a = trim(fread($in, 1));
    $b = trim(fread($in, 2));

    $lcm = $a / gcd($a, $b) * $b;
    fwrite($out, $lcm . PHP_EOL);

    fclose($in);
    fclose($out);
?>