local bt = require("btree")

mytree = bt.new()

mytree.blackboard = {
    name = "mytree",
    state = "one",
}

mytree.root = {
    selector = {
        {
            condition = function(mytree,topic,...) return mytree.blackboard.state == "one" end,
            sequence = {                
                {action = function(mytree,topic,...) print(mytree.blackboard.state) end},
                {action = function(mytree,topic,...) mytree.blackboard.state = "two" end},
                {action = function(mytree,topic,...) mytree:process("switchtonext") end},
            }
        },
        {
            condition = function(mytree,topic,...) return topic == "switchtonext" end,
            action = function(mytree,topic,...) print(mytree.blackboard.state) end,
        },
    }
}

mytree:process(mytree.root)
