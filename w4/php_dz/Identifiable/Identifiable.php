<?php
    class Identifiable {
        private static $nextUID = 0;
        private $uID;

        public function Identifiable() {
            $this->uID = self::$nextUID;
            self::$nextUID += 1;
        }

        public static function getNextUID() {
            return self::$nextUID;
        }
    }
?>