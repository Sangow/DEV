<?php
    include 'Date.h';

    class Passport {
        private $serial, $number;
        private static $lastSerial, $lastNumber;
        private $name, $surname, $dateOfBirth;

        private function validNextSN() {
            if ( self::lastNumber < 999999 ) {
                self::lastNumber += 1;
            } else if ( self::lastSerial[0] == 'Z' && self::lastSerial[1] == 'Z' ) {
                throw new Exception("Max passport amount was reached!");
            } else if ( self::lastSerial[1] == 'Z' ) {
                self::lastSerial[0] = chr(ord(self::lastSerial[0]) + 1);
                self::lastSerial[1] = 'A';
                self::lastNumber = 1;
            } else {
                self::lastSerial[1] = chr(ord(self::lastSerial[1]) + 1);
                self::lastNumber = 1;
            }
        }

        
    }

    }
    // $str = "AA";

    // if ( $str[0] = 'A' ) {
    //     $temp = ord($str[0]);
    //     // $str[0] = chr($temp+1);
    //     $str[0] = chr(ord($str[0])+1);
    //     echo $str;
    // }
?>