<?php
# features/extensions/MyAwesomeExtension.php

use Behat\Behat\Context\Initializer\InitializerInterface;
use Symfony\Component\DependencyInjection\ContainerBuilder;
use Behat\Behat\Context\ContextInterface;
use Behat\Mink\Mink;
use Behat\Behat\Extension\Extension;
use Behat\Behat\Console\Processor\ProcessorInterface;
use Behat\Behat\DependencyInjection\Compiler;
use Symfony\Component\DependencyInjection\Reference,
    Symfony\Component\DependencyInjection\Compiler\CompilerPassInterface;
use Symfony\Component\DependencyInjection\ContainerInterface,
    Symfony\Component\Finder\Finder,
    Symfony\Component\Console\Command\Command,
    Symfony\Component\Console\Input\InputArgument,
    Symfony\Component\Console\Input\InputInterface,
    Symfony\Component\Console\Output\OutputInterface;
use Behat\Behat\Console\Processor\LocatorProcessor;



class MinkAwareInitializer implements InitializerInterface
{
    private $mink;

    public function __construct(Mink $mink)
    {
        $this->mink = $mink;
    }

    public function supports(ContextInterface $context)
    {
        // in real life you should use interface for that
        return method_exists($context, 'setMink');
    }

    public function initialize(ContextInterface $context)
    {
        $context->setMink($this->mink);
    }
}

/**
 * Path locator processor.
 */
class MyLocatorProcessor extends LocatorProcessor
{
    private static $class_list;
    
    public static function getClassList() 
    {
        return self::$class_list;
    }
    
    public function setClassList($list) 
    {
        self::$class_list = $list;
    }

    /**
     * Requires *.php scripts from bootstrap/ folder.
     *
     * @param string $path
     */
    protected function loadBootstrapScripts($path)
    {
        $class_list = array();
        $iterator = Finder::create()
            ->files()
            ->name('*.behat_testing.php')
            ->sortByName()
            ->in($path)
        ;
        foreach ($iterator as $file) {
            $file = (string) $file;
            if (!preg_match('#behat_testing/MyDrupalContext.behat_testing.php#', $file)) {
                require_once($file);
                $class_list[] = $file;
            }
        }
        $this->setClassList($class_list);
    }
}


class DrupalBehatExtension extends Extension
{
    public function load(array $config, ContainerBuilder $container)
    {
        $loader = new Symfony\Component\DependencyInjection\Loader\XmlFileLoader(
            $container,
            new Symfony\Component\Config\FileLocator(__DIR__)
        );
        $loader->load('services.xml');
    }

}

return new DrupalBehatExtension();
