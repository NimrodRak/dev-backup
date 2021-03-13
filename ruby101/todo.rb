require 'csv'
require 'time'

def write_to_csv(todo_list, removed_indices)
  CSV.open('./todo.csv', 'w') do |csv|
    removed_indices.each do |index|
      todo_list[index] = []
    end
    todo_list.each do |row|
      csv << row unless row == []
    end
  end
end

def parse_task
  puts 'task:'
  task = gets.chomp
  puts 'date (in format YYYY-mm-dd)'
  date = gets.chomp
  [task, date]
end

def todo
  todo_list = CSV.read('./todo.csv')
  todo_list.sort! { |a, b| Time.parse(a[1]) <=> Time.parse(b[1]) }
  overdue = []
  todo_list.each_with_index do |row, index|
    overdue.append(row) if Time.parse(row[1]) < Time.now
    puts "[#{index}] You must #{row[0]} until #{Time.parse(row[1]).strftime("%Y %m %d")} "
  end
  overdue.each do |row|
    puts "You are #{((Time.now - Time.parse(row[1])) / (3600 * 24)).floor} day(s) late on #{row[0]}!"
  end
  puts 'When you are done with all your wanted commands, type exit'
  removed_indices = []
  loop do
    command = gets.chomp
    break if command == 'exit'

    cmd_split = command.split
    keyword = cmd_split[0]

    case keyword
    when 'remove'
      removed_indices.append(cmd_split[1].to_i)
    when 'add'
      todo_list.append(parse_task)
    else
      puts 'Invalid command'
    end
  end
  write_to_csv(todo_list, removed_indices)
end
todo
