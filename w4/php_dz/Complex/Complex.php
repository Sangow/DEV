<?php
    class Complex {
        private $real, $imaginary;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($real = 0, $imaginary = 0) {
            $this->real = $this->validate($real);
            $this->imaginary = $this->validate($imaginary);
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }

        public function compare(Complex &$other) {
            if ( $this == $other ) {
                echo $this . " and " . $other . " are equal instances" . PHP_EOL;
            } else {
                echo $this . " and " . $other . " are different instances" . PHP_EOL;
            }
        }

        public function plusEquals(Complex &$other) {
            $this->real += $other->real;
            $this->imaginary += $other->imaginary;
        }

        public function minusEquals(Complex &$other) {
            $this->real -= $other->real;
            $this->imaginary -= $other->imaginary;
        }

        public function plus(Complex &$other) {
            $result = clone $this;

            $result->plusEquals($other);

            return $result;
        }

        public function minus(Complex &$other) {
            $result = clone $this;

            $result->minusEquals($other);

            return $result;
        }

        public function multiply(Complex &$other) {
            $result = clone $this;

            $result->real *= $other->real;
            $result->imaginary *= $other->imaginary;

            return $result;
        }

        public function __toString() {
            if ( $this->imaginary < 0 ) {
                return sprintf("%d%di", $this->real, $this->imaginary);
            } else {
                return sprintf("%d+%di", $this->real, $this->imaginary);
            }
        }
    }
?>