<?php
    include 'Point.php';

    class Car {
        private $fuelAmount, $fuelCapacity, 
                $fuelConsuption, $location, 
                $model;

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

        public function __construct($capacity = 60, $consumption = 0.6,
                                    $model = "Mersedes", $location = null) {
            $this->fuelAmount = 0;
            $this->fuelCapacity = $this->validNum($capacity);
            $this->fuelConsuption = $this->validNum($consumption);
            $this->model = $this->validStr($model);
            $this->location = is_null($location) ? new Point() : $location;
        }

        public function __destruct() {
            unset($this->location);
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }

        public function drive(Point &$destination) {
            $fuelNeeded = $this->location->distance($destination) * $this->fuelConsuption;

            var_dump($fuelNeeded);

            if ( $fuelNeeded > $this->fuelAmount ) {
                throw new Exception("OutofFuel!");
            }

            $this->fuelAmount -= $fuelNeeded;
            $this->location = $destination;
        }

        public function refill($fuel) {
            if ( $this->validNum($fuel) ) {
                if ( $this->fuelAmount + $fuel > $this->fuelCapacity ) {
                    throw new Exception("ToMuchFuel!");
                }
                $this->fuelAmount += $fuel;
            }
        }

        public function __toString() {
            return sprintf("Model: %s;" . PHP_EOL . 
                            "Fuel: %g/%g;" . PHP_EOL . 
                            "Location: " . $this->location . '.', $this->model, $this->fuelAmount, $this->fuelCapacity);
        }
    }
?>