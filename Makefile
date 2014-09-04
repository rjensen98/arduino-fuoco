.PHONY: clean All

All:
	@echo "----------Building project:[ arduino_fuoco - Release ]----------"
	@$(MAKE) -f  "arduino_fuoco.mk" && $(MAKE) -f  "arduino_fuoco.mk" PostBuild
	@echo "----------Building project:[ unit_testing - Release ]----------"
	@$(MAKE) -f  "unit_testing.mk"
clean:
	@echo "----------Cleaning project:[ arduino_fuoco - Release ]----------"
	@$(MAKE) -f  "arduino_fuoco.mk"  clean
	@echo "----------Cleaning project:[ unit_testing - Release ]----------"
	@$(MAKE) -f  "unit_testing.mk" clean
