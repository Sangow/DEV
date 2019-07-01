<?php
    include 'Paper.php';

    class Pen{
        private $inkAmount, $inkCapacity;

        private function validStr($str) {
            if ( is_string($str) ) {
                return $str;
            }
            throw new Exception("Invalid input string!");
        }

        public function __construct($inkCapacity = 4096) {
            $this->inkAmount = 0;
            $this->inkCapacity = $inkCapacity;
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
        }

        public function write(Paper &$paper, $message) {
            if ( $this->validStr($message) ) {
                if ( empty($this->inkAmount) ) {
                    throw new Exception("OutOfInk!");
                }
                if ( $this->inkAmount < strlen($message) ) {
                    $paper->addContent(substr($message, 0, $this->inkAmount));
                    $this->inkAmount = 0;
                    return;
                }

                $paper->addContent($message);
                $this->inkAmount -= strlen($message);
            }
        }

        public function refill() {
                $this->inkAmount = $this->inkCapacity;
        }
    }
?>