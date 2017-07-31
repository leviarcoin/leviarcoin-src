# CMake generated Testfile for 
# Source directory: /Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests
# Build directory: /Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CoreTests "core_tests" "--generate_and_play_test_data")
add_test(CryptoTests "crypto_tests" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/crypto/tests.txt")
add_test(DifficultyTests "difficulty_tests" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Difficulty/data.txt")
add_test(hash-fast "hash_tests" "fast" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-fast.txt")
add_test(hash-slow "hash_tests" "slow" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-slow.txt")
add_test(hash-tree "hash_tests" "tree" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-tree.txt")
add_test(hash-extra-blake "hash_tests" "extra-blake" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-extra-blake.txt")
add_test(hash-extra-groestl "hash_tests" "extra-groestl" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-extra-groestl.txt")
add_test(hash-extra-jh "hash_tests" "extra-jh" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-extra-jh.txt")
add_test(hash-extra-skein "hash_tests" "extra-skein" "/Users/marco/Desktop/XLC/Clients/fork-v1/leviarcoin-official/tests/Hash/tests-extra-skein.txt")
add_test(HashTargetTests "hash_target_tests")
add_test(SystemTests "system_tests")
add_test(UnitTests "unit_tests")
