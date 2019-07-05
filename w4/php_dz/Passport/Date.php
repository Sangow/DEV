<?php
    class Date {
        private $day, $month, $year;

        public function __construct($day = 1, $month = 1, $year = 1970) {
            if ( !checkdate($month, $day, $year) ) {
                throw new Exception("Invalid date!");
            }
            $this->day = $day;
            $this->month = $month;
            $this->year = $year;
        }

        public function __toString() {
            return sprintf("%02d.%02d.%d", $this->day, $this->month, $this->year);
        }
    }
?>