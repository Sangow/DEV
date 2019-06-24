<?php
    class Point {
        public $x, $y;

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
                throw new Exception("Attribute error: attribute $name not found");
            }
        }

        public function distance(Point $other) {
            return hypot($this->x - $other->x, $this->y - $other->y);
        }

        public function __toString() {
            return sprintf("(%d, %d)", $this->x, $this->y);
        }

        public function compare(Point $other) {
            if ( $this == $other ) {
                echo $this . " is equal to " . $o2 .PHP_EOL;
            } else {
                echo $this . " is not equal to " . $o2 .PHP_EOL;
            }
        }

        public function isSameInstance(Point &$other) {
            if ( $this == $other ) {
                echo $this . " and  " . $other . " are references to the same instance" . PHP_EOL;
            } else {
                echo $this . " and  " . $other . " is different instances" . PHP_EOL;
            }
        }
    }

        $p1 = new Point(10, 10);
        $p2 = new Point();
    
        $p1->compare($p2);
    
        $p1->x = 1000;
    
        echo $p1 . PHP_EOL;
    
        $p3 = clone $p1;
    
        echo $p3 . PHP_EOL;
    
        $p1->compare($p3);
    
        $p1->isSameInstance($p3);
?>