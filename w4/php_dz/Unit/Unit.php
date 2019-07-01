<?php
    class Unit {
        private $damage, $hitPoints,
                $hitPointsLimit, $name;

        private function ensureIsAlive() {
            if ( empty($this->hitPoints) ) {
                throw new Exception("UnitIsDead!");
            }
        }

        private function validNum($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid input num value!");
            
        }

        private function validStr($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new Exception("Invalid input string value!");
        }

        public function __construct($name, $hp, $dmg) {
            $this->damage = $this->validNum($dmg);
            $this->hitPoints = $this->hitPointsLimit = $this->validNum($hp);
            $this->name = $this->validStr($name);
        }

        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute $name not found!");
        }

        public function addHitPoints($hp) {
            $this->ensureIsAlive();
            if ( $this->validNum($hp) ) {
                echo $this->name . " restored health!" . PHP_EOL;

                if ( $hp > $this->hitPointsLimit -$this->hitPoints ) {
                    $this->hitPoints = $this->hitPointsLimit;
                    return;
                }

                $this->hitPoints += $hp;
            }
        }

        public function takeDamage($dmg) {
            $this->ensureIsAlive();

            if ( $dmg > $this->hitPoints ) {
                $this->hitPoints = 0;
                return;
            }

            $this->hitPoints -= $dmg;
        }

        public function counterAttack(Unit &$enemy) {
            $enemy->takeDamage($this->damage / 2);
            echo $this->name . " counterattacked " . $enemy->name . PHP_EOL;
        }

        public function attack(Unit &$enemy) {
            $enemy->takeDamage($this->damage);

            echo $this->name . " attacked " . $enemy->name . PHP_EOL;

            $enemy->counterAttack($this);
        }

        public function __toString() {
            if ( !empty($this->hitPoints) ) {
                return sprintf("Name:\t%s;" . PHP_EOL .
                                "DMG:\t%d;" . PHP_EOL .
                                "HP:\t%d/%d.", $this->name,
                                                        $this->damage,
                                                        $this->hitPoints, $this->hitPointsLimit);
            }
            return sprintf("[R.I.P.] %s is DEAD [R.I.P.]", $this->name);
        }
    }
?>