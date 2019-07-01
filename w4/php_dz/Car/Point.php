<?php
    class Point {
        private $x, $y;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($x = 0, $y = 0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw Exception("Attribute error: attribute $name not found");
        }

        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw Exception("Attribute error: attribute $name not found");
            }
        }

        public function distance(Point &$other) {
            return hypot($this->x - $other->x, $this->y - $other->y);
        }

        public function compare(Point &$other) {
            if ( $this == $other ) {
                echo $this . " is equal to " . $other .PHP_EOL;
            } else {
                echo $this . " is not equal to " . $other .PHP_EOL;
            }
        }

        public function __toString() {
            return sprintf("(%d, %d)", $this->x, $this->y);
        }
    }
?>