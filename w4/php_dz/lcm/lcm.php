<?php
    function gcd($a, $b) {
        if ( $b == 0 ) {
            return $a;
        }
        return gcd($b, $a % $b);
    }

    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");

    list($a, $b) = explode(' ', trim(fgets($in)));

    $lcm = $a / gcd($a, $b) * $b;
    fwrite($out, $lcm . PHP_EOL);

    fclose($in);
    fclose($out);
?>