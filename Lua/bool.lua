-- only judge true or false

function true_or_false(bool)
    bool = not(bool == false)
    return bool
end

print ("true",tostring(true_or_false(true)))
print ("false",tostring(true_or_false(false)))


