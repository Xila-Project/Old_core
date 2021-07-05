# Changelog

All notable changes to this project will be documented in this file.

This project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.1.0] - 2021-04-20

- Initial release.

## Unreleased [0.2.0]

### Added

- Add mosfet to switch display supply.
- Add dock defragmentation.
- Add flash management to the API.
- Add memory management to the API.
- Add Get_Cycle_Count to Time module.
- Add WiFi automatic reconnection.
- Add dynamic memory management within Shell
- Add mathematic features to the API.

### Changed

- Move Get_Free_Heap() from system to memeory module.
- Improve display power management.
- Increase precision of battery level readings (update battery library).
- Fix simon registry loading.
- Fix deprecated function in Periodic (with "as.<const char*()>" instead of "as.<char*>()").
- Update sound driver.
- Modify Internet Browser home page.

### Removed

- Remove WiFi power sleep mode patch (power button interrupt conflict).



