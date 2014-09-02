.PHONY: clean All

All:
	@echo "----------Building project:[ unit_testing - Release ]----------"
	@$(MAKE) -f  "unit_testing.mk"
clean:
	@echo "----------Cleaning project:[ unit_testing - Release ]----------"
	@$(MAKE) -f  "unit_testing.mk" clean
