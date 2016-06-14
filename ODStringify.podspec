Pod::Spec.new do |s|
  s.name         = 'ODStringify'
  s.version      = '1.0.0'
  s.summary      = 'Stringify fucntions, classes, properties and defines '
  s.homepage     = 'https://github.com/Rogaven/ODStringify'
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { 'Alexey Nazaroff' => 'alexx.nazaroff@gmail.com' }
  s.source       = { :git => 'https://github.com/Rogaven/ODStringify.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.6'
  s.watchos.deployment_target = '1.0'
  s.tvos.deployment_target = '1.0'

  s.requires_arc = true
  
  s.framework    = 'Foundation'
  
  s.source_files = 'src/**/*'
  s.public_header_files = 'src/include/**/*'
  
  #s.dependency ''
end

