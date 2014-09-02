.PHONY: clean All

All:
	@echo "----------Building project:[ arduino_fuoco - Release ]----------"
	@$(MAKE) -f  "arduino_fuoco.mk" && $(MAKE) -f  "arduino_fuoco.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ arduino_fuoco - Release ]----------"
	@$(MAKE) -f  "arduino_fuoco.mk" clean
