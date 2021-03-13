require 'mail'

options = { address: "smtp.gmail.com",
            port: 587,
            user_name: 'nimrodstorage@gmail.com',
            password: 'efwwhgaagrshpqqo',
            authentication: 'plain',
            enable_starttls_auto: true  }

Mail.defaults do
  delivery_method :smtp, options
end
Mail.deliver do
  to 'nimrod.rak@mail.huji.ac.il'
  from 'nimrodstorage@gmail.com'
  subject 'Spotifying'
  body(ARGV[0] == '1' ? 'Hallo! I am currently spotifying. This is an automated Message, Tschuss!' : 'Done Spotifying')
end

