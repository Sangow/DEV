<?php
    class Gun {
        private $amount, $capacity, 
                $isReady, $model, 
                $totalShots;

        private function validNum($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        private function validStr($model) {
            if ( is_string($model) ) {
                return $model;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($model = "Beretta", $capacity = 8) {
            $this->amount = 0;
            $this->capacity = $this->validNum($capacity);
            $this->isReady = false;
            $this->model = $this->validStr($model);
            $this->totalShots = 0;
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }

        public function prepare() {
            if ( !$this->isReady ) {
                $this->isReady = true;
            }
        }

        public function reload() {
            $this->amount = $this->capacity;
            echo $this->model . " reloaded!" . PHP_EOL;
        }

        public function shoot() {
            if ( !$this->isReady ) {
                throw new Exception("NotReady!");
            }

            if ( empty($this->amount) ) {
                throw new Exception("OutOfRounds!");
            }

            echo "BANG!" . PHP_EOL;
            $this->amount -= 1;
            $this->totalShots += 1;
        }

        public function __toString() {
            return sprintf("Gun model: %s;" . PHP_EOL
                        . "Amount: %d/%d;" . PHP_EOL
                        . "Total shots: %d.", $this->model,
                                                $this->amount, $this->capacity,
                                                $this->totalShots);
        }
    }
?>