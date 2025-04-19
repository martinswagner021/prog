-- -----------------------------------------------------
-- Table `studies`.`projeto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `studies`.`projeto` (
  `codigo` INT(11) NOT NULL,
  `titulo` VARCHAR(100) NOT NULL,
  `financiador` VARCHAR(45) NULL DEFAULT NULL,
  `departamento` INT(11) NOT NULL,
  PRIMARY KEY (`codigo`),
  INDEX `fk_depto_idx` (`departamento` ASC) VISIBLE,
  CONSTRAINT `fk_depto`
    FOREIGN KEY (`departamento`)
    REFERENCES `studies`.`departamento` (`codigo`)
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1;
