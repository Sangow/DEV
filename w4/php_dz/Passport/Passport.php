<?php
    include 'Date.php';

    class Passport {
        private $serial, $number;
        private static $lastSerial, $lastNumber;
        private $name, $surname, $dateOfBirth;

        // private function validNextSN() {
        //     if ( self::lastNumber < 999999 ) {
        //         self::lastNumber += 1;
        //     } else if ( self::lastSerial[0] == 'Z' && self::lastSerial[1] == 'Z' ) {
        //         throw new Exception("Max passport amount was reached!");
        //     } else if ( self::lastSerial[1] == 'Z' ) {
        //         self::lastSerial[0] = chr(ord(self::lastSerial[0]) + 1);
        //         self::lastSerial[1] = 'A';
        //         self::lastNumber = 1;
        //     } else {
        //         self::lastSerial[1] = chr(ord(self::lastSerial[1]) + 1);
        //         self::lastNumber = 1;
        //     }
        // }

        private function validStr($value) {
            if ( ctype_alpha($value) ) {
                return $value;
            }
            throw new Exception("Invalid input string value!");
        }

        private static function validNextSN() {
            if ( self::$lastNumber < 999999 ) {
                self::$lastNumber += 1;
            } else if ( self::$lastSerial == 'ZZ' ) {
                throw new Exception("Max passport amount was reached!");
            } else {
                self::$lastSerial++;
                self::$lastNumber = 1;
            }
        }

        public function __construct($name = "Kon", $surname = "Cheniy", Date &$date = null) {
            if ( !self::$lastSerial ) {
                self::$lastSerial = 'AA';
                self::$lastNumber = 0;
            }
            self::validNextSN();
            $this->serial = self::$lastSerial;
            $this->number = self::$lastNumber;

            $this->name = $this->validStr($name);
            $this->surname = $this->validStr($surname);

            if ( is_null($date) ) {
                $this->dateOfBirth = new Date();
            } else {
                $this->dateOfBirth = $date;
            }
        }

        public static function setSN($serial, $number = 1) {
            if ( strlen($serial) > 2 || !ctype_upper($serial) ) {
                throw new Exception("Invalid serial!");
            }
            if ( $number < 1 || $number > 999999 ) {
                throw new Exception("Invalid number!");
            }
            self::$lastSerial = $serial;
            self::$lastNumber = $number - 1;
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
        }

        public function __toString() {
            return sprintf("Name:\t\t%s;". PHP_EOL .
                            "Surname:\t%s;" . PHP_EOL .
                            "S/N:\t\t%s %06d;" . PHP_EOL .
                            "Date of birth:\t%s.", $this->name,
                                                    $this->surname,
                                                    $this->serial, $this->number,
                                                    $this->dateOfBirth);
        }
    }
?>