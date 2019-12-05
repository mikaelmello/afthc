builtin_create_set:
  mema $0, 3
  mema $1, 1
  mov $0[0], 1
  mov $0[1], 0
  mov $0[2], $1
  return $0

builtin_find_set:
  mov $0, #0[2]
  mov $2, #0[1]
  mov $1, 0
  seq $3, $1, $2
  brnz builtin_find_set_ret0, $3

  builtin_find_set_loop:
  mov $6, $0[$1]
  seq $3, $6, #1
  brnz builtin_find_set_ret1, $3      
  add $1, $1, 1
  slt $3, $1, $2
  brnz builtin_find_set_loop, $3

  builtin_find_set_ret0:
  return 0
  builtin_find_set_ret1:
  return 1

builtin_insert_set:
  push #0
  push #1
  call builtin_find_set, 2
  pop $0
  brnz builtin_insert_set_ret1, $0

  mov $0, #0[2]
  mov $2, #0[1]
  mov $3, #0[0]

  slt $4, $2, $3
  brnz builtin_insert_set_insert, $4

 
  mul $5, $3, 2
  mema $6, $5
  mov #0[0], $5

 
  mov $1, 0
  seq $5, $1, $2

  builtin_insert_set_loop:
  mov $7, $0[$1]
  mov $6[$1], $7
  add $1, $1, 1
  slt $5, $1, $2
  brnz builtin_insert_set_loop, $5

  builtin_insert_set_move:
  mov $9, #0[2]
  memf $9
  mov #0[2], $6
  mov $0, #0[2]

  builtin_insert_set_insert:
  mov $0[$2], #1
  add $8, $2, 1
  mov #0[1], $8

  builtin_insert_set_ret1:
  return #1

builtin_remove_set:
  mov $0, #0[2] // array
  mov $2, #0[1] // count
  mov $3, #0[0] // capacity

  brz builtin_insert_set_ret1, $2

  // copy all to new
  mov $1, 0
  seq $5, $1, $2 // $5 = $1 == $2
  brnz builtin_insert_set_ret1, $5

  mov $11, 0

  builtin_remove_set_loop:


  brz builtin_remove_set_check_until_equal, $11

  mov $6, $0[$1]
  sub $12, $1, 1
  mov $0[$12], $6
  jump builtin_remove_set_increment

  builtin_remove_set_check_until_equal:
  mov $6, $0[$1]
  seq $11, $6, #1
  builtin_remove_set_increment:
  add $1, $1, 1       // increment 1
  slt $3, $1, $2
  brnz builtin_remove_set_loop, $3   // if i < count, repeat

  sub $2, $2, 1
  mov #0[1], $2

  builtin_remove_set_ret1:
  return #1
