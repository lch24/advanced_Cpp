mkdir -p include/dummies

# 生成dummy头文件
for i in $(seq 0 999); do
  cat > include/dummies/dummy$i.h <<EOF
// dummy header file $i
#pragma once

constexpr int dummy_value_$i = $i;
EOF
done

# 生成load_all.h，先清空文件
echo "// Auto-generated includes" > include/load_all.h
for i in $(seq 0 999); do
  echo "#include \"dummies/dummy$i.h\"" >> include/load_all.h
done
