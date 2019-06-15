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
            $this->x =
        }
    }
?>