t = {4,1,2,3}

table.sort(t, function(a,b) return a > b end)

print(table.unpack(t))