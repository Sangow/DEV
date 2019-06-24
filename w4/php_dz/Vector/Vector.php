<?php
    class Vector {
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
            throw new Exception("Attribute error: attribute $name not found");
            
        }

        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw new Exception("Attribute error: attribute $name not found");
            }
        }

        public function len() {
            return hypot($this->x, $this->y);
        }

        public function compare(Vector  &$other) {
            if ( $this == $other ) {
                echo $this . " and " . $other . " are references to the same instance" . PHP_EOL;
            } else {
                echo $this . " and " . $other . " is different instances" . PHP_EOL;
            }
        }

        public function plusEquals(Vector &$other) {
            $this->x += $other->x;
            $this->y += $other->y;
        }

        public function minusEquals(Vector &$other) {
            $this->x -= $other->x;
            $this->y -= $other->y;
        }

        public function plus(Vector &$other) {
            $result = clone $this;

            $result->plusEquals($other);

            return $result;
        }

        public function minus(Vector &$other) {
            $result = clone $this;

            $result->minusEquals($other);

            return $result;
        }

        public function __toString() {
            return sprintf("(%d, %d)", $this->x, $this->y);
        }
    }

    $v1 = new Vector(1, 1);
    $v2 = new Vector(10, 10);

    echo $v1 . PHP_EOL;
?>