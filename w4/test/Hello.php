<?php
    // class Point {
    //     private $x;
    //     private $y;

    //     private function validate($value) {
    //         if ( is_numeric($value) ) {
    //             return $value;
    //         } else {
    //             throw new Exception("Value is not numeric!");
                
    //         }
    //     }

    //     public function Point($x, $y) {
    //         $this->x = $this->validate($x);
    //         $this->y = $this->validate($y);
    //     }

    //     // public function __debugInfo() {
    //     //     return "zalupa";
    //     // }

    //     // function __destruct() {
    //     //     echo "_______Destructing__object_______" . PHP_EOL;
    //     //     $this->x = null;
    //     //     $this->y = null;
    //     // }

    //     public function getX() {
    //         return $this->x;
    //     }

    //     public function getY() {
    //         return $this->y;
    //     }

    //     public function setX($x) {
    //         $this->x = $this->validate($x);
    //     }

    //     public function setY($y) {
    //         $this->y = $this->validate($y);
    //     }

    //     public function distance(Point $other) {
    //         return hypot($this->x - $other->x, $this->y - $other->y);
    //     }

    //     public function __toString() {
    //         return sprintf("(%g, %g)", $this->x, $this->y);
    //     }
    // }

    // function compare($x, $y) {
    //     if ( $x == $y ) {
    //         echo $x . " and " . $y . " are equal!" . PHP_EOL;
    //     } else {
    //         echo $x . " and " . $y . " are NOT equal!" . PHP_EOL;
    //     }
    // }

    // function isTheSameInstance($x, $y) {
    //     if ( $x === $y ) {
    //         echo $x . " and " . $y . " are references of the same instance!" . PHP_EOL;
    //     } else {
    //         echo $x . " and " . $y . " are different instances!" . PHP_EOL;
    //     }
    // }

    // print_r(new Point(2, 4));

    $a = false;
    $b = true;

    var_dump(empty($a), empty($b));
?>